#include "TerrainComponent.h"

const Component::ComponentType TerrainComponent::COMPONENT_TYPE = TERRAIN_COMPONENT;

TerrainComponent::TerrainComponent(
  const int id,
  RawModel* rawModel,
  const float x, const float z)
  : Component(id), rawModel_(rawModel), x_(x*SIZE), y_(0.0f), z_(z*SIZE)
{
}
