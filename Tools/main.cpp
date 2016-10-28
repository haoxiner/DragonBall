#include "XEMD.h"
#include "XESK.h"
#include "XEAN.h"
#include "XEMB.h"
#include "XEMM.h"
#include "SceneNode.h"
#include <vector>
#include <string>
#include <iostream>
#include <queue>

void loadModels(const std::string& folder)
{
  std::string character_name = "GOK";
  std::string character_index = "000";
  std::string character_prefix = folder + character_name + "/" + character_name + "_" + character_index;
  std::string skeleton_filename = character_prefix + ".esk";
  std::string animation_filename = "GOK/GOK.ean";

  XESK *eskSkeleton = nullptr;
  eskSkeleton = new XESK();
  if (eskSkeleton->load(skeleton_filename))
  {
    //FILE *fp = fopen("D:/log.log", "w");
    
    auto skeleton = eskSkeleton->CreateXSkeleton();
  }
  else
  {
    delete eskSkeleton;
    eskSkeleton = nullptr;
  }
  
  XEAN *animation = new XEAN();
  if (animation->load(animation_filename))
  {
    animation->CreateXAnimation();
  }
  else
  {
    delete animation;
    animation = nullptr;
  }
  
  std::vector<std::string> modelNames;
  modelNames.push_back(character_prefix + "_Bust");
  modelNames.push_back(character_prefix + "_Boots");
  modelNames.push_back(character_prefix + "_Face_base");
  modelNames.push_back(character_prefix + "_Face_eye");
  modelNames.push_back(character_prefix + "_Face_forehead");
  modelNames.push_back(character_prefix + "_Pants");
  modelNames.push_back(character_prefix + "_Rist");
 
  // per EMD per SceneNode
  for (size_t i = 0; i < modelNames.size(); i++)
  {
    auto embFileName = modelNames[i] + ".emb";
    auto embDytFileName = modelNames[i] + ".dyt.emb";
    XEMB* texturePack = new XEMB();
    if (texturePack->load(embFileName))
    {
      texturePack->createXTextures();
    }
    else
    {
      delete texturePack;
      texturePack = nullptr;
    }
    XEMB* textureDytPack = new XEMB();
    if (textureDytPack->load(embFileName))
    {
      textureDytPack->createXTextures();
    }
    else
    {
      delete textureDytPack;
      textureDytPack = nullptr;
    }
    XEMM* material = new XEMM();
    if (material->load(modelNames[i] + ".emm"))
    {
      material->SetTexturePack(texturePack);
      material->SetTextureDytPack(textureDytPack);
      material->CreateXMaterials();
    }
    else
    {
      delete material;
      material = nullptr;
    }
    XEMD* model = new XEMD();
    if (model->load(modelNames[i] + ".emd"))
    {
      if (eskSkeleton)
      {
        //model->SetSkeleton(eskSkeleton);
      }
      //model->SetMaterialPack(material);
      //SceneNode* sceneNode = model->CreateSceneNode();
    }
    else
    {
      delete model;
      model = nullptr;
    }
    if (model)
    {
      delete model;
    }
    if (texturePack)
    {
      delete texturePack;
    }
    if (textureDytPack)
    {
      delete textureDytPack;
    }
    if (material)
    {
      delete material;
    }
  }
}


int main()
{
  loadModels("D:/G/Extract/data/data/chara/");
  return 0;
}