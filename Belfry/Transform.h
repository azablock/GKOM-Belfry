#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "BlfComponent.h"

class Transform : public BlfComponent {
public:
  void const awake() {}
  void const update() {}

  const void translate(glm::vec3 vector);
  const void scale(glm::vec3 vector);
  const void rotate(glm::vec3 vector);

  glm::vec3 position() const;
  glm::vec3 scale() const;
  glm::vec3 rotation() const;

private:
  glm::vec3 _position;
  glm::vec3 _scale;
  glm::vec3 _rotation;
};