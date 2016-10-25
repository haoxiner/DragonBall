#pragma once
#include <vector>
/*
* per mesh per EMB&EMD file
*/
class XMesh
{
public:
  std::vector<float> vertices_;
  std::vector<float> normals_;
  std::vector<float> texCoords_;
  std::vector<int> indices_;
  int alphaTextureIndex_;
  int shadingTextureIndex_;
  uint8_t materialType_;
  uint8_t boneIDs_[4];
  uint8_t boneWeights_[4];

};