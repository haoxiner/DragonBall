#pragma once
#include "RenderingComponent.h"
#include "WorldPositionComponent.h"
#include "TerrainComponent.h"
#include "RawModel.h"
#include <vector>
#include <map>

class ComponentManager
{
public:
  inline std::map<RawModel*, std::vector<RenderingComponent>> &GetRenderingComponentsMap() { return renderingComponentsMap_; }
  inline std::vector<WorldPositionComponent> &GetWorldPositionComponents() { return worldPositionComponents_; }
  inline std::vector<TerrainComponent> &GetTerrainComponents() { return terrainComponents_; }

  RenderingComponent* CreateRenderingComponent(RawModel* rawModel)
  {
    auto renderingVector = &renderingComponentsMap_[rawModel];
    renderingVector->push_back(RenderingComponent(0, rawModel));
    return &(renderingVector->back());
  }
  WorldPositionComponent* CreateWorldPositionComponent()
  {
    int id = renderingComponentsMap_.size();
    worldPositionComponents_.push_back(WorldPositionComponent(id));
    return &worldPositionComponents_.back();
  }
  TerrainComponent* CreateTerrainComponent(
    RawModel* rawModel,
    const float x, const float z)
  {
    int id = terrainComponents_.size();
    terrainComponents_.push_back(TerrainComponent(id, rawModel, x, z));
    return &terrainComponents_.back();
  }
private:
  std::map<RawModel*, std::vector<RenderingComponent>> renderingComponentsMap_;
  std::vector<WorldPositionComponent> worldPositionComponents_;
  std::vector<TerrainComponent> terrainComponents_;
};