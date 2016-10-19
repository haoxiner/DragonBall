#pragma once
#include "Entity.h"
#include "TerrainComponent.h"

class Terrain : public Entity
{
public:
  virtual void Initialize();
  virtual void Update(float deltaTime);
private:
  TerrainComponent *terrainComponent_;
  static const int SIZE = 800;
  static const int VERTEX_COUNT = 256;
};