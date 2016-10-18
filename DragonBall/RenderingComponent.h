#pragma once
#include "Component.h"
#include "RawModel.h"
#include <vector>

class RenderingComponent : public Component
{
public:
  RenderingComponent() {}
  const static ComponentType COMPONENT_TYPE;
  virtual ComponentType GetComponentType();
  RawModel *rawModel_;
private:
};