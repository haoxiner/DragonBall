#pragma once
#include "Component.h"
#include "RawModel.h"

class TerrainComponent : public Component
{
public:
  TerrainComponent(const int id, RawModel* rawModel, const float x, const float y);
  static const ComponentType COMPONENT_TYPE;
  const RawModel* GetRawModel() const { return rawModel_; }
  float GetX() { return x_; }
  float GetZ() { return z_; }
  static const int SIZE = 100;
  static const int VERTEX_COUNT = 256;
private:
  RawModel* rawModel_;
  float x_, y_, z_;
};