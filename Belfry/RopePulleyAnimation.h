#pragma once

#include <GLFW/glfw3.h>
#include "Animation.h"
#include "Transform.h"

class RopePulleyAnimation : public Animation {
public:
  RopePulleyAnimation(glm::vec3 rotationAxis, glm::vec3 rotationPoint) {
    this->length = 3.0f;
    this->amplitude = 0.5f;
    this->rotationAxis = rotationAxis;
    this->rotationPoint = rotationPoint;
  }

  RopePulleyAnimation(glm::vec3 rotationAxis, glm::vec3 rotationPoint, GLfloat amplitude) {
    this->length = 3.0f;
    this->amplitude = amplitude;
    this->rotationAxis = rotationAxis;
    this->rotationPoint = rotationPoint;
  }

  virtual void animate(BlfObject* target) {
    auto transform = target->getComponent<Transform>();
    auto angle = amplitude * glm::cos(glfwGetTime());

    transform->rotation = glm::vec3(rotationAxis);
    transform->rotationCenter = rotationPoint;
    transform->rotationAngle = angle;
  }

private:
  GLfloat amplitude;
  glm::vec3 rotationAxis;
  glm::vec3 rotationPoint;
};