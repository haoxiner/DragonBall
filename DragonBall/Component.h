#pragma once
#include <cstdint>
// include entity.h caused a dependent loop
class Entity;

class Component
{
public:
  enum ComponentType
  {
    WORLD_POSITION_COMPONENT,
    RENDER_COMPONENT,
    TERRAIN_COMPONENT,
    CHARACTER_RENDERING_COMPONENT
  };
  Entity *entity_;
  int GetID() { return id_; }
  void SetID(int id) { id_ = id; }
protected:
  Component(int id);
private:
  int id_;
};