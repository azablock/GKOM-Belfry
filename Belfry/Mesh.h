#pragma once

#include <GL\glew.h>
#include <vector>
#include "Texture.h"
#include "Vertex.h"

struct Mesh {
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  
  //std::vector<Texture> textures;
  //zakladam ze jeden mesh moze miec max. 1 teksture
  Texture texture;
};