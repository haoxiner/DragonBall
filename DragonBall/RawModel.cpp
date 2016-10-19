#include "RawModel.h"

RawModel::RawModel() :vaoID_(0), indicesCount_(0)
{
}

RawModel::RawModel(const GLuint vaoID, const int indicesCount)
  :vaoID_(vaoID), indicesCount_(indicesCount)
{
}

RawModel::~RawModel()
{
}