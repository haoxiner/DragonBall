#include "RenderingSystem.h"
#include "RenderComponent.h"
#include "WorldPositionComponent.h"
#include "OpenGLHeader.h"
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

void RenderingSystem::Update(float deltaTime, std::vector<Entity*> &entities)
{
  // traverse entities multiple times to use diffrent types of shaders to render
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for (auto entity : entities)
  {
    if (Match(entity))
    {
      entity->Update(deltaTime);
      auto renderComp = entity->GetComponent<RenderComponent>();
      auto worldPositionComp = entity->GetComponent<WorldPositionComponent>();
      staticShader_->Use();
      staticShader_->LoadViewMatrix(*camera_);
      glm::mat4 modelMatrix;
      modelMatrix = glm::scale(modelMatrix, glm::vec3(1.0f));
      modelMatrix = glm::translate(modelMatrix, worldPositionComp->position_);
      //glm::rotate(modelMatrix, worldPositionComp->position_.z, glm::vec3(0.0f, 0.0f, 1.0f));
      staticShader_->LoadModelMatrix(modelMatrix);
      glBindVertexArray(renderComp->rawModel_->vaoID_);
      glEnableVertexAttribArray(0);
      glEnableVertexAttribArray(1);
      glEnableVertexAttribArray(2);
      glDrawElements(GL_TRIANGLES, renderComp->rawModel_->indicesCount_, GL_UNSIGNED_INT, (void*)0);
      glDisableVertexAttribArray(0);
      glDisableVertexAttribArray(1);
      glDisableVertexAttribArray(2);
      glBindVertexArray(0);
      staticShader_->Release();
    }
  }
}

void RenderingSystem::SetCamera(Camera *camera)
{
  camera_ = camera;
}
