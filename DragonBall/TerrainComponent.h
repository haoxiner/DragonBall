#pragma once
#include "Component.h"
#include "RawModel.h"

class TerrainComponent : public Component
{
public:
  TerrainComponent(const int id, const RawModel &rawModel);
  const static ComponentType COMPONENT_TYPE;
  virtual ComponentType GetComponentType() const;
  const RawModel &GetRawModel() const { return rawModel_; }
private:
  RawModel rawModel_;
};