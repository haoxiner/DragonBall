#pragma once
#include <glm/glm.hpp>
#include <string>
#include <vector>

namespace DragonBall
{
class Bone
{
public:
  Bone(const std::string& name);
  ~Bone();
  void AddChild(Bone* child);
  void SetTransformation(const glm::mat4& transformation);
  const std::string& GetName() const { return name_; }
  const std::vector<Bone*>& GetChildren() const { return children_; }
  const glm::mat4& GetTransformation() const { return transformation_; }
private:
  std::vector<Bone*> children_;
  glm::mat4 transformation_;
  std::string name_;
};
}