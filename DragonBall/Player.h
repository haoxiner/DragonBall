#pragma once
#include "Entity.h"
#include "WorldPositionComponent.h"
#include "RenderComponent.h"

class Player : public Entity
{
public:
  virtual void Initialize();
  virtual void Update(float deltaTime);
private:
  WorldPositionComponent *positionComponent_;
  RenderComponent *renderComponent_;
};