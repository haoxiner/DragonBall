#pragma once
#include "Entity.h"
#include "WorldPositionComponent.h"
#include "RenderingComponent.h"

class Player : public Entity
{
public:
  virtual void Initialize();
  virtual void Update(float deltaTime);
private:
  WorldPositionComponent *positionComponent_;
  RenderingComponent *renderComponent_;
};