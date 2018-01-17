#pragma once

#include <glm\glm.hpp>

class Vertex {
public:
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec2 textureCoordinates;

  Vertex(glm::vec3 position, glm::vec2 textureCoordinates) {
    this->position = position;
    this->textureCoordinates = textureCoordinates;
    this->normal = glm::vec3(0.0f, 0.0f, 0.0f);
  }

  Vertex() {}
};