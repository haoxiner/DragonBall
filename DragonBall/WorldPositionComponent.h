#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <vector>

class WorldPositionComponent : public Component
{
public:
  WorldPositionComponent(const int id);
  const static ComponentType COMPONENT_TYPE;
  glm::vec3 position_;
  float rotateX_, rotateY_, rotateZ_;
};