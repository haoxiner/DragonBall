#pragma once
#include "OpenGLHeader.h"
class RawModel
{
public:
  RawModel();
  RawModel(const GLuint vaoID, const int indicesCount);
  ~RawModel();
  GLuint vaoID_;
  unsigned indicesCount_;
};