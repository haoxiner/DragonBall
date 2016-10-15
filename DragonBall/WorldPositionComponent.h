#pragma once
#include "Component.h"
#include <glm/glm.hpp>

class WorldPositionComponent : public Component
{
public:
  const static ComponentType COMPONENT_TYPE;
  virtual ComponentType GetComponentType();
private:
  glm::vec3 position_;
  float rotateX_, rotateY_, rotateZ_;
};