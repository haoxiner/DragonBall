#include "System.h"
ComponentManager *System::componentManager_ = nullptr;
void System::SetComponentManager(ComponentManager * componentManager)
{
  componentManager_ = componentManager;
}

bool System::Match(Entity *entity)
{
  return Component::Match(entity->GetRelatedComponentType(), GetRelatedComponentType());
}
