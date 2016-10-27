#include "Skeleton.h"

DragonBall::Skeleton::Skeleton()
{
}

DragonBall::Skeleton::~Skeleton()
{
}

DragonBall::Bone* DragonBall::Skeleton::CreateBone(const std::string& boneName)
{
  auto bone = new DragonBall::Bone(boneName);
  bones_.push_back(bone);
  return bone;
}
