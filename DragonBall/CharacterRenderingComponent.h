#pragma once
#include <glm/glm.hpp>
#include <vector>

class CharacterRenderingUnit
{
public:
  int alphaTextureID_;
  int shadingTextureID_;
  int materialType_;
  // glDrawElements(......, indicesOffset * SIZE_PER_INDEX);
  int indicesOffset_;
};

class CharacterRenderingComponent
{
public:
  std::vector<CharacterRenderingUnit> renderingUnits_;
  std::vector<glm::mat4> boneTransforms_;
  int vaoID_;
};