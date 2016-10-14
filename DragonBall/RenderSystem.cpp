#include "RenderSystem.h"
#include "RenderComponent.h"

Component::ComponentType RenderSystem::GetRelatedComponentType()
{
  const Component::ComponentType relatedComponent =
    Component::POSITION_COMPONENT &
    Component::RENDER_COMPONENT;
  return relatedComponent;
}

void RenderSystem::Update(float deltaTime, Entity *entity)
{
  RenderComponent *renderComponent = entity->GetComponent<RenderComponent>();
}
