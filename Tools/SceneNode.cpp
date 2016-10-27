#include "SceneNode.h"

SceneNode::~SceneNode()
{
  for (auto node : children_)
  {
    delete node;
  }
}

SceneNode* SceneNode::CreateChild()
{
  SceneNode* child = new SceneNode();
  children_.push_back(child);
  return child;
}
