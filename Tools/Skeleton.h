#pragma once
#include "Bone.h"
#include <string>
#include <vector>

namespace DragonBall
{
class Skeleton
{
public:
  Skeleton();
  ~Skeleton();
  Bone* CreateBone(const std::string& boneName);
  const std::vector<Bone*>& GetBones() { return bones_; }
private:
  std::vector<Bone*> bones_;
};
}