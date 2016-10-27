#pragma once
#include <vector>
class SceneNode
{
public:
  ~SceneNode();
  SceneNode* CreateChild();

private:
  std::vector<SceneNode*> children_;
};