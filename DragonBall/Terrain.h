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
};