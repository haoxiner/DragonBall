#include "RenderingSystem.h"
#include "RenderingComponent.h"
#include "WorldPositionComponent.h"
#include "OpenGLHeader.h"
#include "ComponentManager.h"
#include <glm/gtc/matrix_transform.hpp>

RenderingSystem::RenderingSystem()
{
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glFrontFace(GL_CCW);
  //glEnable(GL_BLEND);
  //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  staticShader_ = new StaticShader();
  terrainShader_ = new TerrainShader();
  glm::mat4 projectionMatrix = glm::perspective(glm::radians(60.0f), 4.0f / 3.0f, 0.01f, 10000.0f);
  staticShader_->Use();
  staticShader_->LoadProjectionMatrix(projectionMatrix);
  staticShader_->Release();
  terrainShader_->Use();
  terrainShader_->LoadProjectionMatrix(projectionMatrix);
  terrainShader_->Release();
}

RenderingSystem::~RenderingSystem()
{
  delete staticShader_;
}

void RenderingSystem::ProcessEntity(Entity *entity)
{
}

// There should be different kinds of shaders
// every shader behaves differently
// e.g player may change its shader (e.g become transparent)
void RenderingSystem::Update(float deltaTime, std::vector<Entity*> &entities)
{
  glClearColor(0.9f, 0.3f, 0.4f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  auto RenderingComponentMap = componentManager_->GetRenderingComponentsMap();
  if (!RenderingComponentMap.empty())
  {
    staticShader_->Use();
    staticShader_->LoadViewMatrix(*camera_);
    for (auto rawModelRenderingComponent : RenderingComponentMap)
    {
      auto rawModel = rawModelRenderingComponent.first;
      glBindVertexArray(rawModel->vaoID_);
      glEnableVertexAttribArray(0);
      glEnableVertexAttribArray(1);
      glEnableVertexAttribArray(2);
      
      for (auto renderingComponent : rawModelRenderingComponent.second)
      {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, renderingComponent.texID_);
        staticShader_->LoadTexture("image", 0);
        glActiveTexture(GL_TEXTURE0 + 1);
        glBindTexture(GL_TEXTURE_2D, renderingComponent.alphaID_);
        staticShader_->LoadTexture("aimage", 1);
        auto worldPositionComp = renderingComponent.entity_->GetComponent<WorldPositionComponent>();

        glm::mat4 modelMatrix;
        modelMatrix = glm::translate(modelMatrix, worldPositionComp->position_);
        modelMatrix = glm::scale(modelMatrix, glm::vec3(1.0f));
        modelMatrix = glm::rotate(modelMatrix, worldPositionComp->rotateY_, glm::vec3(0.0f, 1.0f, 0.0f));

        staticShader_->LoadModelMatrix(modelMatrix);
        glDrawElements(GL_TRIANGLES, rawModel->indicesCount_ / 2, GL_UNSIGNED_INT, (void*)(3 * 4));
        glBindTexture(GL_TEXTURE_2D, 0);
      }
      glDisableVertexAttribArray(0);
      glDisableVertexAttribArray(1);
      glDisableVertexAttribArray(2);
      glBindVertexArray(0);
    }
    staticShader_->Release();
  }
  auto terrainComponents = componentManager_->GetTerrainComponents();
  terrainShader_->Use();
  terrainShader_->LoadViewMatrix(*camera_);
  for (auto terrainComponent : terrainComponents)
  {
    auto rawModel = terrainComponent.GetRawModel();
    glBindVertexArray(rawModel->vaoID_);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glm::mat4 modelMatrix;
    modelMatrix = glm::translate(modelMatrix, glm::vec3(terrainComponent.GetX(), 0.0f, terrainComponent.GetZ()));
    terrainShader_->LoadModelMatrix(modelMatrix);
    glDrawElements(GL_TRIANGLES, rawModel->indicesCount_, GL_UNSIGNED_INT, (void*)0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
  }
  terrainShader_->Release();
}

void RenderingSystem::SetCamera(Camera *camera)
{
  camera_ = camera;
}
