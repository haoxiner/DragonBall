#include "Player.h"
#include "Input.h"
#include "Log.h"
#include <cmath>

void Player::Initialize()
{
  positionComponent_ = GetComponent<WorldPositionComponent>();
  renderComponent_ = GetComponent<RenderingComponent>();
}

void Player::Update(float deltaTime)
{
  positionComponent_->rotateY_ -= glm::radians(90.0f * Input::GetLeftTriggerX() * deltaTime);
  float s = Input::GetLeftTriggerY() * deltaTime;
  positionComponent_->position_.x += s * std::sinf(positionComponent_->rotateY_);
  positionComponent_->position_.z += s * std::cosf(positionComponent_->rotateY_);
}
