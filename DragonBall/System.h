#pragma once
#include "Entity.h"
#include "Component.h"
#include <vector>

class ComponentManager;
class System
{
public:
  virtual void ProcessEntity(Entity *entity) = 0;
  virtual void Update(float deltaTime, std::vector<Entity*> &entities) = 0;
  static void SetComponentManager(ComponentManager *componentManager);
protected:
  virtual Component::ComponentType GetRelatedComponentType() = 0;
  bool Match(Entity *entity);
  static ComponentManager *componentManager_;
private:
};