#pragma once
class Input
{
public:
  static void SetLeftTriggerX(const float x) { leftTriggerX_ = x; }
  static void SetLeftTriggerY(const float y) { leftTriggerY_ = y; }
  static float GetLeftTriggerX() { return leftTriggerX_; }
  static float GetLeftTriggerY() { return leftTriggerY_; }

  static void SetRightTriggerX(const float x) { rightTriggerX_ = x; }
  static void SetRightTriggerY(const float y) { rightTriggerY_ = y; }
  static float GetRightTriggerX() { return rightTriggerX_; }
  static float GetRightTriggerY() { return rightTriggerY_; }
private:
  static float leftTriggerX_;
  static float leftTriggerY_;
  static float rightTriggerX_;
  static float rightTriggerY_;
};