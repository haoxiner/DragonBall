#pragma once
#include "Component.h"
#include "RawModel.h"
#include <vector>

class RenderingComponent : public Component
{
public:
  RenderingComponent(const int id, const RawModel &rawModel);
  const static ComponentType COMPONENT_TYPE;
  RawModel rawModel_;
private:
};