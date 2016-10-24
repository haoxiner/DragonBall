#pragma once
#include <map>
#include <string>
#include <vector>

class CharacterModel
{
public:
  CharacterModel();
  ~CharacterModel();

private:
  std::vector<int> alphaTextures_;
  std::vector<int> shadingTextures_;

  std::vector<int> alphaTextureIndices_;
  std::vector<int> shadingTextureIndices_;
  std::vector<int> materialIndices_;
  int vaoID_;
};