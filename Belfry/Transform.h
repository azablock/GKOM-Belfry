#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "BlfComponent.h"

class Transform : public BlfComponent {

public:  
  void const awake() {
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    scale = glm::vec3(1.0f, 1.0f, 1.0f);
    rotation = glm::vec3(1.0f, 1.0f, 1.0f);
  }

  void const update() {}

  glm::vec3 position;
  glm::vec3 scale;
  glm::vec3 rotation;
};