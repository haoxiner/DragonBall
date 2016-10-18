#pragma once
#include <cstdint>
// include entity.h caused a dependent loop
class Entity;

class Component
{
public:
  typedef std::uint64_t ComponentType;
  static const ComponentType WORLD_POSITION_COMPONENT = 1;
  static const ComponentType RENDER_COMPONENT = 2;
  static bool Match(ComponentType key, ComponentType lock)
  {
    return lock == (key & lock);
  }
  static ComponentType Merge(ComponentType keyA, ComponentType keyB)
  {
    return (keyA | keyB);
  }
  virtual ComponentType GetComponentType() = 0;
  Entity *entity_;
  int GetID() { return id_; }
  void SetID(int id) { id_ = id; }
protected:
  Component() {}
private:
  int id_;
};