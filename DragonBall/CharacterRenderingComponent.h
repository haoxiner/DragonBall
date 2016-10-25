#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <vector>
#include <map>

class CharacterTextureWrapper
{
public:
  int alphaTextureID_;
  int shadingTextureID_;
};

class CharacterRenderingUnit
{
public:
  int materialType_;
  // glDrawElements(......, indicesOffset * SIZE_PER_INDEX);
  int indicesOffset_;
};

class CharacterRenderingComponent : public Component
{
public:
  static const Component::ComponentType TYPE;
  CharacterRenderingComponent(int id);
public:
  std::map<CharacterTextureWrapper, std::vector<CharacterRenderingComponent>> renderingUnits_;
  std::vector<glm::mat4> boneTransforms_;
  int vaoID_;
};