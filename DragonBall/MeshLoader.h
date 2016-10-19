#pragma once
#include <string>
#include <vector>

class MeshLoader
{
public:
  bool LoadMesh(
    const std::string &filepath,
    std::vector<float> &vertices,
    std::vector<float> &normals,
    std::vector<float> &texCoords,
    std::vector<int> &indices);
private:

};