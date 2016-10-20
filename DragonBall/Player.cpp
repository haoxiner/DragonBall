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
  positionComponent_->position_.z -= 10.0f * Input::GetLeftTriggerY() * deltaTime;
  positionComponent_->rotateY_ += glm::radians(20.0f * Input::GetLeftTriggerX() * deltaTime);
}
