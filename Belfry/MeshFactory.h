#pragma once

#include <GL/glew.h>
#include "Mesh.h"

class MeshFactory {
public:
  virtual Mesh* newInstance(std::string imagePath) = 0;
};