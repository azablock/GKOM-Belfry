#pragma once

#include "Animation.h"
#include "Transform.h"

class RotationAnimation : public Animation {
public:
  RotationAnimation(float length, glm::vec3 rotationAxis) {
    this->length = length;
    this->rotationSpeed = 0.5f;
    this->rotationAxis = rotationAxis;
  }

  void animate(BlfObject* target) {
    auto transform = target->getComponent<Transform>();

    transform->rotation = glm::vec3(rotationAxis);
    transform->rotationAngle += glm::radians(rotationSpeed);

    if (transform->rotationAngle >= 360.0f) {
      transform->rotationAngle = 0.0f;
    }
  }

  GLfloat rotationSpeed;
  glm::vec3 rotationAxis;
};