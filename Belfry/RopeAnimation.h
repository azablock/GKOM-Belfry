#pragma once

#include <GLFW/glfw3.h>
#include "Animation.h"
#include "Transform.h"

class RopeAnimation : public Animation {
public:
  RopeAnimation(glm::vec3 rotationAxis, glm::vec3 rotationPoint) {
    this->length = 3.0f;
    this->amplitude = 0.5f;
    this->rotationAxis = rotationAxis;
    this->rotationPoint = rotationPoint;
  }

  RopeAnimation(glm::vec3 rotationAxis, glm::vec3 rotationPoint, GLfloat amplitude) {
    this->length = 3.0f;
    this->amplitude = amplitude;
    this->rotationAxis = rotationAxis;
    this->rotationPoint = rotationPoint;
  }

  virtual void animate(BlfObject* target) {
    auto transform = target->getComponent<Transform>();
    auto currentTime = glm::cos(glfwGetTime());
    auto scaleDelta = amplitude * glm::abs(glm::cos(currentTime));
    auto positionDelta = amplitude * glm::cos(currentTime);

    transform->scale = glm::vec3(transform->scale.x, scaleDelta + 1.0f, transform->scale.z);//scaleAxis
    transform->position = glm::vec3(transform->position.x, -positionDelta + 5.0f, transform->position.z);//scaleAxis
  }

private:
  GLfloat amplitude;
  glm::vec3 rotationAxis;
  glm::vec3 rotationPoint;
};