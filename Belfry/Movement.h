#pragma once

#include <glm\glm.hpp>
#include "BlfComponent.h"
#include "Transform.h"

class Movement : public BlfComponent {
public:

  const void awake() {
    _movementVector = new glm::vec3(0.0f, 0.0f, 0.0f);
    _transform = parent()->getComponent<Transform>();
  };
  
  const void update() {
    //_transform->position += _movementVector;
  };

  void changeMovementSpeed(glm::vec3 delta) {
    //_movementVector += delta;
  }

private:
  glm::vec3* _movementVector;
  Transform* _transform;
};