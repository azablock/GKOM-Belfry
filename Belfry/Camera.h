#pragma once

#include <glm/glm.hpp>
#include "BlfComponent.h"
#include "Transform.h"

class Camera : public BlfComponent {
public:
  const void awake() {
    _lookDirection = glm::vec3(0.0f, 0.0f, 0.0f);
    _cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    _cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
  }

  const void update() {
    auto transform = _parent->getComponent<Transform>();
    _view = glm::lookAt(transform->position, _lookDirection, _cameraUp);
  }

private:
  glm::mat4 _view;
  glm::vec3 _cameraUp;
  glm::vec3 _cameraFront;
  glm::vec3 _lookDirection; //todo probably will be public
};

//The glm::LookAt function requires a position, target and up vector respectively