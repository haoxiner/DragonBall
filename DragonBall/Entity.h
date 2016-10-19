#pragma once
#include "Component.h"
#include "Log.h"
#include <cassert>
#include <map>

class Entity
{
public:
  virtual void Initialize() = 0;
  virtual void Update(float deltaTime) = 0;
  template<class T> void AddComponent(T *component)
  {
    component->entity_ = this;
    components_[T::COMPONENT_TYPE] = component;
  }
  template<class T> T *GetComponent() {
    return reinterpret_cast<T*>(components_[T::COMPONENT_TYPE]);
  }
private:
  std::map<Component::ComponentType, Component*> components_;
};