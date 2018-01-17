#pragma once

#include "Animation.h"
#include "Transform.h"

class RotationAnimation : public Animation {
public:
  RotationAnimation(float length, glm::vec3 rotationAxis) {
    this->length = length;
    this->rotationDelta = 0.5f;
    this->rotationAxis = rotationAxis;
    this->rotationPoint = glm::vec3(0.0f, 0.0f, 0.0f);
  }

  RotationAnimation(float length, glm::vec3 rotationAxis, glm::vec3 rotationPoint) {
    this->length = length;
    this->rotationDelta = 0.5f;
    this->rotationAxis = rotationAxis;
    this->rotationPoint = rotationPoint;
  }

  RotationAnimation(float length, glm::vec3 rotationAxis, glm::vec3 rotationPoint, GLfloat rotationDelta) {
    this->length = length;
    this->rotationDelta = 0.5f;
    this->rotationAxis = rotationAxis;
    this->rotationPoint = rotationPoint;
  }

  void animate(BlfObject* target) {
    auto transform = target->getComponent<Transform>();

    transform->rotation = glm::vec3(rotationAxis);
    transform->rotationCenter = rotationPoint;
    transform->rotationAngle += glm::radians(rotationDelta);

    if (transform->rotationAngle >= 360.0f) {
      transform->rotationAngle = 0.0f;
    }
  }

private:
  GLfloat rotationDelta;
  glm::vec3 rotationAxis;
  glm::vec3 rotationPoint;
};