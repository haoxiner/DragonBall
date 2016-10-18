#include "Player.h"
#include "Log.h"

void Player::Initialize()
{
  positionComponent_ = GetComponent<WorldPositionComponent>();
  renderComponent_ = GetComponent<RenderingComponent>();
}

void Player::Update(float deltaTime)
{
  positionComponent_->position_.y += glm::radians(30.0f) * deltaTime;
}
