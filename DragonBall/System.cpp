#include "System.h"

bool System::Match(Entity *entity)
{
  return Component::Match(entity->GetRelatedComponentType(), GetRelatedComponentType());
}
