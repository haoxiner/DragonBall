#include "TerrainComponent.h"

const Component::ComponentType TerrainComponent::COMPONENT_TYPE = TERRAIN_COMPONENT;

TerrainComponent::TerrainComponent(const int id) : Component(id)
{
}

Component::ComponentType TerrainComponent::GetComponentType() const
{
  return ComponentType();
}
