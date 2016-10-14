#pragma once
#include "System.h"
#include "Component.h"

class RenderSystem : public System
{
protected:
  virtual Component::ComponentType GetRelatedComponentType();
  virtual void Update(float deltaTime, Entity* entity);
private:    
};