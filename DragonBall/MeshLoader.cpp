#include "MeshLoader.h"
#include "LibXenoverse/LibXenoverse.h"
#include "Log.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

bool MeshLoader::LoadMesh(
  const std::string &filepath,
  std::vector<float> &vertices,
  std::vector<float> &normals,
  std::vector<float> &texCoords,
  std::vector<int> &indices)
{
  Assimp::Importer importer;
  const aiScene *scene = importer.ReadFile(filepath, aiProcessPreset_TargetRealtime_Fast);
  if (scene == nullptr)
  {
    return false;
  }
  for (int meshIndex = 0; meshIndex < 1; meshIndex++)
  {
    aiMesh *mesh = scene->mMeshes[meshIndex];
    for (int i = 0; i < mesh->mNumVertices; i++)
    {
      vertices.push_back(mesh->mVertices[i].x);
      vertices.push_back(mesh->mVertices[i].y);
      vertices.push_back(mesh->mVertices[i].z);

      normals.push_back(mesh->mNormals[i].x);
      normals.push_back(mesh->mNormals[i].y);
      normals.push_back(mesh->mNormals[i].z);

      texCoords.push_back(mesh->mTextureCoords[0][i].x);
      texCoords.push_back(mesh->mTextureCoords[0][i].y);
    }
    for (int i = 0; i < mesh->mNumFaces; i++)
    {
      indices.push_back(mesh->mFaces[i].mIndices[0]);
      indices.push_back(mesh->mFaces[i].mIndices[1]);
      indices.push_back(mesh->mFaces[i].mIndices[2]);
    }
  }
  importer.FreeScene();
  return true;
}

void MeshLoader::GenerateTerrain(
  const int SIZE,
  const int VERTEX_COUNT,
  std::vector<float> &vertices,
  std::vector<float> &normals,
  std::vector<float> &texCoords,
  std::vector<int> &indices)
{
  for (int x = 0; x < VERTEX_COUNT; x++)
  {
    for (int z = 0; z < VERTEX_COUNT; z++)
    {
      vertices.push_back(((float)x) / (VERTEX_COUNT - 1) * SIZE);
      vertices.push_back(0.0f);
	  vertices.push_back(((float)z) / (VERTEX_COUNT - 1) * SIZE);
      normals.push_back(0.0f);
      normals.push_back(1.0f);
      normals.push_back(0.0f);
      texCoords.push_back(((float)x) / (VERTEX_COUNT - 1));
      texCoords.push_back(((float)z) / (VERTEX_COUNT - 1));
    }
  }
  for (int x = 0; x < VERTEX_COUNT - 1; x++)
  {
    for (int z = 0; z < VERTEX_COUNT - 1; z++)
    {
      int bottomLeft = x * VERTEX_COUNT + z;
      int bottomRight = bottomLeft + 1;
      int topLeft = (x + 1) * VERTEX_COUNT + z;
      int topRight = topLeft + 1;
      indices.push_back(bottomLeft);
      indices.push_back(topRight);
      indices.push_back(topLeft);
      indices.push_back(bottomLeft);
      indices.push_back(bottomRight);
      indices.push_back(topRight);
    }
  }
}

class EMDCustom : public LibXenoverse::EMD
{
public:
  bool LoadEMD(
    const std::string& filepath,
    std::vector<float>& vertices,
    std::vector<float>& normals,
    std::vector<float>& texCoords,
    std::vector<int>& indices)
  {
    if (!load(filepath))
    {
      return false;
    }
    auto model = models[2];
    auto mesh = model->getMeshes()[0];
    auto submesh = mesh->getSubmeshes()[1];
    auto triangles = submesh->getTriangles()[0];
    auto verts = submesh->getVertices();
    for (auto v : verts)
    {
      vertices.push_back(v.x);
      vertices.push_back(v.y);
      vertices.push_back(v.z);
      normals.push_back(v.nx);
      normals.push_back(v.ny);
      normals.push_back(v.nz);
      texCoords.push_back(v.u);
      texCoords.push_back(v.v);
    }
    for (auto i : triangles.faces)
    {
      indices.push_back(i);
    }
    return true;
  }

};

bool MeshLoader::LoadEMD(const std::string& filepath, std::vector<float>& vertices, std::vector<float>& normals, std::vector<float>& texCoords, std::vector<int>& indices)
{
  EMDCustom emd;
  return emd.LoadEMD(filepath, vertices, normals, texCoords, indices);
}
