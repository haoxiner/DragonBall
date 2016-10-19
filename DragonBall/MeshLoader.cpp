#include "MeshLoader.h"
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
