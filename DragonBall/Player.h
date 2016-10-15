#pragma once
#include "Entity.h"
#include "PositionComponent.h"


class Player : public Entity
{
public:
  Player();
  virtual void Update(float deltaTime);
private:
  WorldPositionComponent *positionComponent_;
};