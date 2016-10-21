#include "Engine.h"
#include <algorithm>

void Engine::Update(float deltaTime)
{
  // if FPS < 60, we treat it as 60 to ensure the logic behaves well.
  // This method may cause problems when game support network cooperation.
  // synchronize deltatime to 60.0f per frame may be a choice.
  if (deltaTime > 1.0f / 60.0f)
  {
    deltaTime = 1.0f / 60.0f;
  }
  for (auto entity : entities_)
  {
    entity->Update(deltaTime);
  }
  for (auto system : systems_)
  {
    system->Update(deltaTime, entities_);
  }
}

void Engine::ProcessEntity(Entity * entity)
{
  entity->Initialize();
  entities_.push_back(entity);
}

void Engine::Remove(Entity *entity)
{
  // find the entity and change it to the last element, then pop_back
  auto entityIter = std::find(entities_.begin(), entities_.end(), entity);
  if (entityIter != entities_.end())
  {
    *entityIter = entities_.back();
    entities_.pop_back();
  }
}
