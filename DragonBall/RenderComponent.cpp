#include "RenderComponent.h"

const Component::ComponentType RenderComponent::COMPONENT_TYPE = RENDER_COMPONENT;

Component::ComponentType RenderComponent::GetComponentType()
{
  return COMPONENT_TYPE;
}