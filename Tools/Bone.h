#pragma once
#include <glm/glm.hpp>
#include <string>
#include <vector>

namespace DragonBall
{
class Bone
{
public:
  Bone(const std::string& name, const int id);
  ~Bone();
  void AddChild(Bone* child);
  void SetTransformation(const glm::mat4& transformation);
  const std::string& GetName() const { return name_; }
  const std::vector<Bone*>& GetChildren() const { return children_; }
  const glm::mat4& GetTransformation() const { return transformation_; }
  const int GetID() { return id_; }
private:
  std::vector<Bone*> children_;
  glm::mat4 transformation_;
  std::string name_;
  int id_;
};
}