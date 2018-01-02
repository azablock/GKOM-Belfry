#pragma once

#include <GL/glew.h>
#include "Mesh.h"

class MeshFactory {
public:
  virtual Mesh* newInstance() = 0;
};