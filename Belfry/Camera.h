#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "BlfComponent.h"
#include "BlfWorld.h"
#include "Transform.h"
#include "Contants.h"

class Camera : public BlfComponent {
public:
  const void awake() {
    _lookDirection = glm::vec3(0.0f, 0.0f, 0.0f);
    _cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    _cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    _fov = 45.0f;
    _aspect = (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT;

    auto fppActor = BlfWorld::instance().getBlfObjectByTag("FppActor");
    _transform = fppActor->getComponent<Transform>();
  }

  const void update() {
    _view = glm::lookAt(_transform->position, _lookDirection + _cameraFront, _cameraUp);
  //  _view = glm::lookAt(_transform->position, _lookDirection, _cameraUp);
    //  glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    _projection = glm::perspective(_fov, _aspect, 0.1f, 100.0f);
  }

  void changeLookDirection(glm::vec3 delta) {
    _lookDirection += delta;
  }

  glm::mat4 view() {
    return _view;
  }

  glm::mat4 projection() {
    return _projection;
  }

  glm::vec3 cameraFront() {
    return _cameraFront;
  }

  glm::vec3 cameraUp() {
    return _cameraUp;
  }

  glm::vec3 _cameraFront;

private:
  glm::mat4 _view;
  glm::mat4 _projection;
  glm::vec3 _cameraUp;
 // glm::vec3 _cameraFront;
  glm::vec3 _lookDirection;
  GLfloat _fov;
  GLfloat _aspect;
  Transform* _transform;
};