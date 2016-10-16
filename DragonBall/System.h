#pragma once
#include "Entity.h"
#include "Component.h"
#include <vector>

class System
{
public:
  virtual void Update(float deltaTime, std::vector<Entity*> &entities) = 0;
protected:
  virtual Component::ComponentType GetRelatedComponentType() = 0;
  bool Match(Entity *entity);
private:
};