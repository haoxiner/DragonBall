#pragma once
#include "RawModel.h"

class Terrain
{
public:
  Terrain();
  ~Terrain();

private:
  RawModel rawModel;
  const float x_;
  const float y_;
  static const int SIZE = 800;
  static const int VERTEX_COUNT = 256;
};