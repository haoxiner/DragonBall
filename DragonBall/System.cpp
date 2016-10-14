#include "System.h"

void System::Update(float deltaTime, std::vector<Entity*> entities)
{
  for (auto entity : entities)
  {
    if (Component::Match(entity->GetRelatedComponentType(), GetRelatedComponentType()))
    {
      Update(deltaTime, entity);
    }
  }
}
