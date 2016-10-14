#pragma once
#include "Component.h"

class RenderComponent : public Component
{
public:
  const static ComponentType COMPONENT_TYPE;
  virtual ComponentType GetComponentType();
private:

};