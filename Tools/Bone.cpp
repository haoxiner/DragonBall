#include "Bone.h"

DragonBall::Bone::Bone(const std::string& name, const int id)
  :name_(name), id_(id)
{
}

DragonBall::Bone::~Bone()
{
}

void DragonBall::Bone::AddChild(Bone* child)
{
  children_.push_back(child);
}

void DragonBall::Bone::SetTransformation(const glm::mat4& transformation)
{
  transformation_ = transformation;
}
