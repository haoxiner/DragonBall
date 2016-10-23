#include "Engine.h"
#include "Display.h"
#include "Player.h"
#include "RawModel.h"
#include "Loader.h"
#include "RenderingSystem.h"
#include "RenderingComponent.h"
#include "Camera.h"
#include "Log.h"
#include "ComponentManager.h"
#include "MeshLoader.h"
#include "Terrain.h"
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
  
  Loader loader;
  std::vector<float> vertices;
  std::vector<float> normals;
  std::vector<float> texCoords;
  std::vector<int> indices;
  
  MeshLoader meshLoader;
  //meshLoader.LoadMesh("D:/GameDev/Resources/Akai_E_Espiritu.fbx", vertices, normals, texCoords, indices);
  vertices.clear();normals.clear();texCoords.clear();indices.clear();
  meshLoader.LoadEMD("D:/GameDev/GOK_000_Bust.emd", vertices, normals, texCoords, indices);
  //meshLoader.LoadQuad(vertices, normals, texCoords, indices);

  ComponentManager componentManager;
  System::SetComponentManager(&componentManager);

  Player player;
  auto renderComp = componentManager.CreateRenderingComponent(loader.LoadToVAO(vertices, normals, texCoords, indices));
  renderComp->texID_ = loader.LoadTexture("D:/GameDev/DATA000.dds");
  renderComp->alphaID_ = loader.LoadTexture("D:/GameDev/DATA001.dds");
  //renderComp->texID_ = loader.LoadDDS("D:/G/Extract/data/data/chara/GOK/GOK_000_Bust.dyt/DATA001.dds");
  if (renderComp->texID_ == 0)
  {
    return -1;
  }
  player.AddComponent(renderComp);

  auto worldPositionComp = componentManager.CreateWorldPositionComponent();
  worldPositionComp->position_ = glm::vec3(0.0f);
  worldPositionComp->rotateX_ = 0.0f;
  worldPositionComp->rotateY_ = 0.0f;
  worldPositionComp->rotateZ_ = 0.0f;
  player.AddComponent(worldPositionComp);
  Camera camera;
  camera.position_ = glm::vec3(-1.0f, 0.5f, -1.0f);
  camera.yaw_ = 225.0f;

  vertices.clear();normals.clear();texCoords.clear();indices.clear();
  meshLoader.GenerateTerrain(TerrainComponent::SIZE, TerrainComponent::VERTEX_COUNT, vertices, normals, texCoords, indices);
  auto terrainComp = componentManager.CreateTerrainComponent(loader.LoadToVAO(vertices, normals, texCoords, indices), 0, 0);
  Terrain terrain;
  terrain.AddComponent(terrainComp);

  RenderingSystem renderingSystem;
  renderingSystem.SetCamera(&camera);

  Engine engine;
  engine.ProcessEntity(&player);
  engine.ProcessEntity(&terrain);
  engine.AddSystem(&renderingSystem);

 
  
  // then another thread starts to load resources.
  while (display.IsRunning())
  {
    float deltaTime = display.GetDelta();
    engine.Update(deltaTime);
    display.Update();
  }


  return 0;
}