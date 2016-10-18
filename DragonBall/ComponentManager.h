#pragma once
#include "RenderingComponent.h"
#include "WorldPositionComponent.h"
#include <vector>

class ComponentManager
{
public:
  inline std::vector<RenderingComponent> &GetRenderingComponents() { return renderingComponents_; }
  inline std::vector<WorldPositionComponent> &GetWorldPositionComponents() { return worldPositionComponents_; }
  template<class T> T *CreateComponent() { return nullptr; }
  template<> RenderingComponent *CreateComponent()
  {
    RenderingComponent renderingComponent;
    int id = renderingComponents_.size();
    renderingComponent.SetID(id);
    renderingComponents_.push_back(renderingComponent);
    return &renderingComponents_.back();
  }
  template<> WorldPositionComponent *CreateComponent()
  {
    WorldPositionComponent worldPositionComponent;
    int id = renderingComponents_.size();
    worldPositionComponent.SetID(id);
    worldPositionComponents_.push_back(worldPositionComponent);
    return &worldPositionComponents_.back();
  }
private:
  std::vector<RenderingComponent> renderingComponents_;
  std::vector<WorldPositionComponent> worldPositionComponents_;
};