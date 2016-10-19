#pragma once
#include "RenderingComponent.h"
#include "WorldPositionComponent.h"
#include "TerrainComponent.h"
#include <vector>

class ComponentManager
{
public:
  inline std::vector<RenderingComponent> &GetRenderingComponents() { return renderingComponents_; }
  inline std::vector<WorldPositionComponent> &GetWorldPositionComponents() { return worldPositionComponents_; }

  RenderingComponent *CreateRenderingComponent(const RawModel &rawModel)
  {
    int id = renderingComponents_.size();
    renderingComponents_.push_back(RenderingComponent(id, rawModel));
    return &renderingComponents_.back();
  }
  WorldPositionComponent *CreateWorldPositionComponent()
  {
    int id = renderingComponents_.size();
    worldPositionComponents_.push_back(WorldPositionComponent(id));
    return &worldPositionComponents_.back();
  }
  TerrainComponent *CreateTerrainComponent()
  {
    int id = terrainComponents_.size();
    terrainComponents_.push_back(TerrainComponent(id));
    return &terrainComponents_.back();
  }
private:
  std::vector<RenderingComponent> renderingComponents_;
  std::vector<WorldPositionComponent> worldPositionComponents_;
  std::vector<TerrainComponent> terrainComponents_;
};