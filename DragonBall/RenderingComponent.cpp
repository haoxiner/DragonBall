#include "RenderingComponent.h"

const Component::ComponentType RenderingComponent::COMPONENT_TYPE = RENDER_COMPONENT;

RenderingComponent::RenderingComponent(const int id, const RawModel &rawModel)
  :Component(id), rawModel_(rawModel)
{
}
