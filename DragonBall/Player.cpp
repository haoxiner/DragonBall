#include "Player.h"
#include "Input.h"
#include "Log.h"

void Player::Initialize()
{
  positionComponent_ = GetComponent<WorldPositionComponent>();
  renderComponent_ = GetComponent<RenderingComponent>();
}

void Player::Update(float deltaTime)
{
  positionComponent_->position_.y += Input::GetLeftTriggerY() * deltaTime;
  positionComponent_->position_.x += Input::GetLeftTriggerX() * deltaTime;
}
