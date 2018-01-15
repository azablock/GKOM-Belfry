#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "BlfComponent.h"

class Transform : public BlfComponent {

public:  
  void const awake() {
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    scale = glm::vec3(1.0f, 1.0f, 1.0f);
    rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    rotationAngle = 0.0f;
  }

  void const update() {
    //rotate
    if (glm::length(rotation) != 0.0f)
      transformModel = glm::rotate(transformModel, rotationAngle, rotation);

    //scale
    transformModel = glm::scale(transformModel, scale);

    //translate
    transformModel = glm::translate(transformModel, position);
  }

  void const lateUpdate() {
    awake(); //todo inaczej to jakos 
  }

  glm::vec3 position;//translate
  glm::vec3 scale;
  glm::vec3 rotation;
  glm::mat4 transformModel;
  GLfloat rotationAngle;
};