#pragma once
#include "Xenoverse.h"
#include "Skeleton.h"

class XESK : public LibXenoverse::ESK
{
public:
  DragonBall::Skeleton* CreateXSkeleton();
  void BuildBone(unsigned short boneID, DragonBall::Skeleton* skeleton, DragonBall::Bone* parentBoneNode);
private:
};