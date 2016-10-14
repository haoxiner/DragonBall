#pragma once
#include "PositionComponent.h"
#include "RenderComponent.h"
#include <map>

class Entity
{
public:
  virtual void Update(float deltaTime) = 0;
  void AddComponent(Component *component)
  {
    assert(!Component::Match(relatedComponent_, component->GetComponentType()));
    component->entity_ = this;
    components_[component->GetComponentType()] = component;
  }
  Component::ComponentType GetRelatedComponentType()
  {
    return relatedComponent_;
  }
  template<class T> T *GetComponent() {
    assert(Component::Match(relatedComponent_, T::COMPONENT_TYPE));
    return reinterpret_cast<T*>(components_[T::COMPONENT_TYPE]);
  }
private:
  std::map<Component::ComponentType,Component*> components_;
  Component::ComponentType relatedComponent_;
};