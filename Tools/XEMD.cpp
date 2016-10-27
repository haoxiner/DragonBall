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

SceneNode* XEMD::CreateSceneNode()
{
  SceneNode* rootNode = new SceneNode();
  for (auto model : models)
  {
    CreateSceneNodeModel(model, rootNode);
  }
  return rootNode;
}

SceneNode * XEMD::CreateSceneNodeModel(LibXenoverse::EMDModel* model, SceneNode* parent)
{
  auto modelNode = parent->CreateChild();
  std::vector<LibXenoverse::EMDMesh*>& meshes = model->getMeshes();
  for (size_t i = 0; i < meshes.size(); i++)
  {
    vector<LibXenoverse::EMDSubmesh*>& submeshes = meshes[i]->getSubmeshes();
    CreateEntityMeshes(meshes[i]);
  }
  return modelNode;
}

void XEMD::CreateEntityMeshes(LibXenoverse::EMDMesh* mesh)
{
  vector<LibXenoverse::EMDSubmesh*>& submeshes = mesh->getSubmeshes();
  for (auto submesh : submeshes)
  {
    CreateMesh(submesh, mesh->getName());
  }
}

void XEMD::CreateMesh(LibXenoverse::EMDSubmesh* submesh, const std::string& name)
{

}
