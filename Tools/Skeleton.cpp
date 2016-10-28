#include "Skeleton.h"
#include <algorithm>
DragonBall::Skeleton::Skeleton()
{
}

DragonBall::Skeleton::~Skeleton()
{
  for (auto bone : bones_)
  {
    delete bone;
  }
}

DragonBall::Bone* DragonBall::Skeleton::CreateBone(const std::string& boneName)
{
  auto bone = new DragonBall::Bone(boneName, bones_.size());
  bones_.push_back(bone);
  return bone;
}

const DragonBall::Bone* DragonBall::Skeleton::FindBone(const std::string& boneName) const
{
  for (auto bone : bones_)
  {
    if (bone->GetName() == boneName)
    {
      return bone;
    }
  }
  return nullptr;
}
