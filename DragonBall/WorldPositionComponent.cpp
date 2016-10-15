#include "WorldPositionComponent.h"

const Component::ComponentType WorldPositionComponent::COMPONENT_TYPE = WORLD_POSITION_COMPONENT;

Component::ComponentType WorldPositionComponent::GetComponentType()
{
  return COMPONENT_TYPE;
}
