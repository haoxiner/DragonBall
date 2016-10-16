#pragma once
#include "Component.h"
#include "RawModel.h"

class RenderComponent : public Component
{
public:
  const static ComponentType COMPONENT_TYPE;
  virtual ComponentType GetComponentType();
  RawModel *rawModel_;
};