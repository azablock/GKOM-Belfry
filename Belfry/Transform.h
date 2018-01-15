#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "BlfComponent.h"
#include "BlfObject.h"

class Transform : public BlfComponent {

public:  
  void const awake() {
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    scale = glm::vec3(1.0f, 1.0f, 1.0f);
    rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    rotationAngle = 0.0f;
  }

  void const update() {
    glm::mat4 transform;

    //rotate
    if (glm::length(rotation) != 0.0f)
      transform = glm::rotate(transform, rotationAngle, rotation);

    //scale
    transform = glm::scale(transform, scale);

    //translate
    if (glm::length(position) != 0.0f)
      transform = glm::translate(transform, position);

    transformModel = transform;
  }

  glm::vec3 position;//translate
  glm::vec3 scale;
  glm::vec3 rotation;
  glm::mat4 transformModel;
  GLfloat rotationAngle;
};