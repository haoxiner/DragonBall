#include "XESK.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>

DragonBall::Skeleton* XESK::CreateXSkeleton()
{
  auto skeleton = new DragonBall::Skeleton();
  if (!bones.empty())
  {
    BuildBone(0, skeleton, nullptr);
  }
  return skeleton;
}

void XESK::BuildBone(unsigned short boneID, DragonBall::Skeleton* skeleton, DragonBall::Bone* parentBoneNode)
{
  LibXenoverse::ESKBone* eskBone = bones[boneID];
  DragonBall::Bone* bone = skeleton->CreateBone(eskBone->getName());
  if (parentBoneNode)
  {
    parentBoneNode->AddChild(bone);
  }
  glm::mat4 parentMatrix;
  if (eskBone->parent_index < bones.size())
  {
    auto pEskBone = bones[eskBone->parent_index];
    parentMatrix = glm::mat4(
      pEskBone->transform_matrix[0], pEskBone->transform_matrix[1], pEskBone->transform_matrix[2], pEskBone->transform_matrix[3],
      pEskBone->transform_matrix[4], pEskBone->transform_matrix[5], pEskBone->transform_matrix[6], pEskBone->transform_matrix[7],
      pEskBone->transform_matrix[8], pEskBone->transform_matrix[9], pEskBone->transform_matrix[10], pEskBone->transform_matrix[11],
      pEskBone->transform_matrix[12], pEskBone->transform_matrix[13],pEskBone->transform_matrix[14],pEskBone->transform_matrix[15]);
  }
  glm::mat4 transformMatrix(
    eskBone->transform_matrix[0], eskBone->transform_matrix[1], eskBone->transform_matrix[2], eskBone->transform_matrix[3],
    eskBone->transform_matrix[4], eskBone->transform_matrix[5], eskBone->transform_matrix[6], eskBone->transform_matrix[7],
    eskBone->transform_matrix[8], eskBone->transform_matrix[9], eskBone->transform_matrix[10],eskBone->transform_matrix[11],
    eskBone->transform_matrix[12],eskBone->transform_matrix[13],eskBone->transform_matrix[14],eskBone->transform_matrix[15]);
  transformMatrix = transformMatrix * glm::inverse(parentMatrix);
  bone->SetTransformation(transformMatrix);
  for (size_t i = 0; i < bones.size(); i++)
  {
    if (bones[i]->parent_index == boneID)
    {
      BuildBone(i, skeleton, bone);
    }
  }
}
