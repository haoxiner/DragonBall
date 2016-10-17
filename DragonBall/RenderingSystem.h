#pragma once
#include "System.h"
#include "Component.h"
#include "Camera.h"
#include "StaticShader.h"

class RenderingSystem : public System
{
public:
  RenderingSystem();
  ~RenderingSystem();
  virtual void ProcessEntity(Entity *entity);
  virtual void Update(float deltaTime, std::vector<Entity*> &entities);
  void SetCamera(Camera *camera);
protected:
  virtual Component::ComponentType GetRelatedComponentType();
private:
  Camera *camera_;
  StaticShader *staticShader_;
};