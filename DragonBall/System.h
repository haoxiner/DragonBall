#pragma once
#include "Entity.h"
#include "Component.h"
#include <vector>

class System
{
public:
  void Update(float deltaTime, std::vector<Entity*> entities);
protected:
  virtual Component::ComponentType GetRelatedComponentType() = 0;
  virtual void Update(float deltaTime, Entity* entity) = 0;
private:
};