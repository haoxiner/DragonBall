#pragma once
#include "Xenoverse.h"
#include "XEMB.h"

class XEMM : public LibXenoverse::EMM
{
public:
  void SetTexturePack(XEMB* texturePack);
  void SetTextureDytPack(XEMB* textureDytPack);
  void CreateXMaterials();

private:
};