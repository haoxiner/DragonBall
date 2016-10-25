#pragma once
#include "RenderingComponent.h"
#include "WorldPositionComponent.h"
#include "TerrainComponent.h"
#include "CharacterRenderingComponent.h"
#include "RawModel.h"
#include <vector>
#include <map>

class ComponentManager
{
public:
  ComponentManager();
  inline std::vector<WorldPositionComponent>& GetWorldPositionComponents() { return worldPositionComponents_; }
  inline std::vector<TerrainComponent>& GetTerrainComponents() { return terrainComponents_; }
  inline std::vector<CharacterRenderingComponent>& GetCharacterRenderingComponents() { return characterRenderingComponents_; }

  WorldPositionComponent* CreateWorldPositionComponent()
  {
    int id = worldPositionComponents_.size();
    worldPositionComponents_.emplace_back(id);
    return &(worldPositionComponents_.back());
  }
  TerrainComponent* CreateTerrainComponent(
    RawModel* rawModel,
    const float x, const float z)
  {
    int id = terrainComponents_.size();
    terrainComponents_.emplace_back(id, rawModel, x, z);
    return &(terrainComponents_.back());
  }
  CharacterRenderingComponent* CreateCharacterRenderingComponent()
  {
    int id = characterRenderingComponents_.size();
    characterRenderingComponents_.emplace_back(id);
    return &(characterRenderingComponents_.back());
  }
private:
  std::vector<WorldPositionComponent> worldPositionComponents_;
  std::vector<TerrainComponent> terrainComponents_;
  std::vector<CharacterRenderingComponent> characterRenderingComponents_;
};