#include "XEMD.h"

XEMD::XEMD()
  :skeleton_(nullptr)
{
}

void XEMD::SetSkeleton(XESK* skeleton)
{
  skeleton_ = skeleton;
}

void XEMD::SetMaterialPack(XEMM * material)
{
}
