#include "Terrain.h"

void Terrain::Initialize()
{
  terrainComponent_ = GetComponent<TerrainComponent>();
}

void Terrain::Update(float deltaTime)
{
  // Entity->Update should accept something like a MSG
  // When MSG require Terrain to shock, Set it here.
}
