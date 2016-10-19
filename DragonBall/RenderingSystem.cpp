#include "RenderingSystem.h"
#include "RenderingComponent.h"
#include "WorldPositionComponent.h"
#include "OpenGLHeader.h"
#include "ComponentManager.h"
#include <glm/gtc/matrix_transform.hpp>

Component::ComponentType RenderingSystem::GetRelatedComponentType()
{
  const Component::ComponentType relatedComponent =
    Component::Merge(Component::WORLD_POSITION_COMPONENT, Component::RENDER_COMPONENT);
  return relatedComponent;
}

RenderingSystem::RenderingSystem()
{
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glFrontFace(GL_CCW);
  staticShader_ = new StaticShader();
  glm::mat4 projectionMatrix = glm::perspective(glm::radians(60.0f), 4.0f / 3.0f, 0.01f, 10000.0f);
  staticShader_->Use();
  staticShader_->LoadProjectionMatrix(projectionMatrix);
  staticShader_->Release();
}

RenderingSystem::~RenderingSystem()
{
  delete staticShader_;
}

void RenderingSystem::ProcessEntity(Entity *entity)
{
}

void RenderingSystem::Update(float deltaTime, std::vector<Entity*> &entities)
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for (auto renderingComponent : componentManager_->GetRenderingComponents())
  {
    auto worldPositionComp = renderingComponent.entity_->GetComponent<WorldPositionComponent>();
    staticShader_->Use();
    staticShader_->LoadViewMatrix(*camera_);
    glm::mat4 modelMatrix;
    modelMatrix = glm::scale(modelMatrix, glm::vec3(1.0f));
    modelMatrix = glm::translate(modelMatrix, worldPositionComp->position_);
    //modelMatrix = glm::rotate(modelMatrix, worldPositionComp->position_.y, glm::vec3(0.0f, 0.0f, 1.0f));
    staticShader_->LoadModelMatrix(modelMatrix);
    glBindVertexArray(renderingComponent.rawModel_->vaoID_);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glDrawElements(GL_TRIANGLES, renderingComponent.rawModel_->indicesCount_, GL_UNSIGNED_INT, (void*)0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
    staticShader_->Release();
  }
  /*
  // traverse entities multiple times to use diffrent types of shaders to render
  for (auto entity : entities)
  {
    if (Match(entity))
    {
      entity->Update(deltaTime);
      // dispatch renderComponent to different renderer
      // we should design a method to re-dispatch only when entities changed.
       //Temporary method:
      //In a specific renderer, renderComponents are in one array
      //if (renderComponent->entity_ == nullptr)
       // remove from related renderer
      
      
      
    }
  }
  */
}

void RenderingSystem::SetCamera(Camera *camera)
{
  camera_ = camera;
}
