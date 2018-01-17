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
    rotationCenter = glm::vec3(0.0f, 0.0f, 0.0f);
    rotationAngle = 0.0f;
  }

  void const update() {
    glm::mat4 transform;

    //translate
    if (glm::length(position) != 0.0f)
      transform = glm::translate(transform, position);

    //rotate




    if (glm::length(rotation) != 0.0f) {
      transform = glm::translate(transform, rotationCenter);
      transform = glm::rotate(transform, rotationAngle, rotation);
      transform = glm::translate(transform, -rotationCenter);
    }
    
      //scale
    transform = glm::scale(transform, scale);

    transformModel = transform;
  }

  glm::vec3 position;//translate
  glm::vec3 scale;
  glm::vec3 rotation;
  glm::vec3 rotationCenter;
  glm::mat4 transformModel;
  GLfloat rotationAngle;
};