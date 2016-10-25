#include "ComponentManager.h"

ComponentManager::ComponentManager()
{
  worldPositionComponents_.reserve(30);
  terrainComponents_.reserve(10);
  characterRenderingComponents_.reserve(30);
}
