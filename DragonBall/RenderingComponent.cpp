#include "RenderingComponent.h"

const Component::ComponentType RenderingComponent::COMPONENT_TYPE = RENDER_COMPONENT;

Component::ComponentType RenderingComponent::GetComponentType()
{
  return COMPONENT_TYPE;
}
