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
  meshLoader.LoadMesh("D:/GameDev/Resources/teapot.obj", vertices, normals, texCoords, indices);

  ComponentManager componentManager;
  System::SetComponentManager(&componentManager);

  Player player;
  auto renderComp = componentManager.CreateRenderingComponent(loader.LoadToVAO(vertices, normals, texCoords, indices));
  player.AddComponent(renderComp);

  auto worldPositionComp = componentManager.CreateWorldPositionComponent();
  player.AddComponent(worldPositionComp);
  Camera camera;
  camera.position_ = glm::vec3(0.0f, 50.0f, 200.9f);

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
  display.Update();
  display.Update();
  while (display.IsRunning())
  {
    float deltaTime = display.GetDelta();
    engine.Update(deltaTime);
    display.Update();
  }

  return 0;
}