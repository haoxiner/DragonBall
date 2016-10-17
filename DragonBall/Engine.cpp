#include "Engine.h"
#include <algorithm>

void Engine::Update(float deltaTime)
{
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
