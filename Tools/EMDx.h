#pragma once
#include <LibXenoverse/LibXenoverse.h>
#include <vector>
#include <string>

struct Float4
{
  float data[4];
  float operator[](size_t index)
  {
    return data[index];
  }
};
struct Byte4
{
  uint8_t data[4];
  uint8_t operator[](size_t index)
  {
    return data[index];
  }
};

class EMDx : public LibXenoverse::EMD
{
public:
  bool LoadEMD(const char *filepath)
  {
    if (!load(filepath))
    {
      return false;
    }
    auto modelVector = models;
    for (auto model : modelVector)
    {
      auto meshVector = model->getMeshes();
      for (auto mesh : meshVector)
      {
        auto subMeshVector = mesh->getSubmeshes();
        for (auto submesh : subMeshVector)
        {
          auto materialName = submesh->getMaterialName();
          auto definition = submesh->getDefinitions()[0];
          int alphaTextureIndex = definition.tex_index;
          int shadingTextureIndex = definition.tex_index;
          auto vertexVector = submesh->getVertices();
          for (auto v : vertexVector)
          {
            vertices_.push_back(v.x);
            vertices_.push_back(v.y);
            vertices_.push_back(v.z);
            normals_.push_back(v.nx);
            normals_.push_back(v.ny);
            normals_.push_back(v.nz);
            texCoords_.push_back(v.u);
            texCoords_.push_back(v.v);
            for (auto boneID : v.bone)
            {
              boneIDs_.push_back(boneID);
            }
            for (auto boneWeight : v.bone_weight)
            {
              boneWeights_.push_back(boneWeight);
            }
          }
          indexOffsets_.push_back(vertices_.size() / 3);
          auto triangles = submesh->getTriangles();
        }
      }
    }
    return true;
  }

  // per vertex
  std::vector<float> vertices_;
  std::vector<float> normals_;
  std::vector<float> texCoords_;
  std::vector<float> boneWeights_;
  std::vector<uint8_t> boneIDs_;
  // per index set
  std::vector<int> indices_;
  std::vector<int> indexOffsets_;


};