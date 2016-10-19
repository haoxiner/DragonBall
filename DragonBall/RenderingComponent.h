#pragma once
#include "Component.h"
#include "RawModel.h"
#include <vector>

class RenderingComponent : public Component
{
public:
  RenderingComponent(const int id, RawModel *rawModel);
  static const ComponentType COMPONENT_TYPE;
  RawModel *rawModel_;
private:
};