#pragma once
#include "Xenoverse.h"
#include "XESK.h"
#include "XEMM.h"

class XEMD : public LibXenoverse::EMD
{
public:
  XEMD();
  void SetSkeleton(XESK* skeleton);
  void SetMaterialPack(XEMM* material);
  void LoadFromFile(const char* filename)
  {
    load(filename);
    FILE *fp = fopen("D:/log.log", "w");
    for (auto model : models)
    {
      for (auto mesh : model->getMeshes())
      {
        for (auto submesh : mesh->getSubmeshes())
        {

        }
      }
    }
    fclose(fp);
  }

private:
  XESK* skeleton_;
};
