#include "TerrainComponent.h"

const Component::ComponentType TerrainComponent::COMPONENT_TYPE = TERRAIN_COMPONENT;

TerrainComponent::TerrainComponent(const int id, const RawModel &rawModel)
  : Component(id), rawModel_(rawModel)
{
}

Component::ComponentType TerrainComponent::GetComponentType() const
{
  return ComponentType();
}
