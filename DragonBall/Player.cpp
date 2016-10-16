#include "Player.h"
#include "Log.h"

void Player::Initialize()
{
  positionComponent_ = GetComponent<WorldPositionComponent>();
  renderComponent_ = GetComponent<RenderComponent>();
}

void Player::Update(float deltaTime)
{
  positionComponent_->position_.z -= 0.1f * (0.001f * deltaTime);
}
