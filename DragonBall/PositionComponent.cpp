#include "PositionComponent.h"

const Component::ComponentType PositionComponent::COMPONENT_TYPE = POSITION_COMPONENT;

Component::ComponentType PositionComponent::GetComponentType()
{
  return COMPONENT_TYPE;
}
