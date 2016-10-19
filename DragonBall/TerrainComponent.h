#pragma once
#include "Component.h"

class TerrainComponent : public Component
{
public:
  TerrainComponent(const int id);
  const static ComponentType COMPONENT_TYPE;
  virtual ComponentType GetComponentType() const;
private:
};