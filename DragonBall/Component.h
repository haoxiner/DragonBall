#pragma once
#include <cstdint>
// include entity.h caused a dependent loop
class Entity;

class Component
{
public:
  typedef std::uint64_t ComponentType;
  static const ComponentType POSITION_COMPONENT = 1;
  static const ComponentType RENDER_COMPONENT = 2;
  static bool Match(ComponentType key, ComponentType lock)
  {
    return key == (key & lock);
  }
  static ComponentType Merge(ComponentType keyA, ComponentType keyB)
  {
    return (keyA | keyB);
  }
  virtual ComponentType GetComponentType() = 0;
  Entity *entity_;
protected:
  Component() {}
private:
};