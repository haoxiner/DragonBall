#include "Engine.h"
#include "Display.h"

#include "Player.h"
#include "RawModel.h"
#include "Loader.h"

#include "RenderingSystem.h"
#include "RenderComponent.h"
#include "Camera.h"
#include "Log.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <sstream>
int WINAPI wWinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  PWSTR pCmdLine,
  int nCmdShow)
{
  Display display;
  if (!display.Initialize())
  {
    return -1;
  }
  
  RawModel *rawModel = nullptr;
  Loader loader;
  Assimp::Importer importer;
  const aiScene *scene = importer.ReadFile("D:/GameDev/Resources/teapot.obj", aiProcessPreset_TargetRealtime_Fast);
  for (int meshIndex = 0; meshIndex < scene->mNumMeshes; meshIndex++)
  {
    aiMesh *mesh = scene->mMeshes[meshIndex];
    std::vector<float> vertices;
    std::vector<int> indices;
    std::vector<float> normals;
    std::vector<float> texCoords;
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
    rawModel = (loader.LoadToVAO(vertices, normals, texCoords, indices));
  }

  Player player;
  RenderComponent renderComp;
  renderComp.rawModel_ = rawModel;
  player.AddComponent(&renderComp);
  WorldPositionComponent worldPositionComp;
  player.AddComponent(&worldPositionComp);
  Camera camera;
  camera.position_ = glm::vec3(0.0f, 1.0f, 3.9f);

  RenderingSystem renderingSystem;
  renderingSystem.SetCamera(&camera);

  // before adding to engine, entity should contain all components it needs.
  Engine engine;
  engine.ProcessEntity(&player);
  engine.AddSystem(&renderingSystem);
  
  // this loop should start just after display.initialize()
  // then another thread starts to load resources.
  display.Update();
  display.Update();
  while (display.IsRunning())
  {
    float deltaTime = display.GetDelta();
    engine.Update(deltaTime);
    display.Update();
  }

  if (rawModel)
  {
    delete rawModel;
  }
  return 0;
}