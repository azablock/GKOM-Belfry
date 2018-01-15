#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GL/GLU.h>
#include <GL\GL.h>
#include "BlfComponent.h"
#include "BlfWorld.h"
#include "Transform.h"
#include "Contants.h"
#include "WindowContainer.h"

class Camera : public BlfComponent {
public:
  const void awake() {
    _lookDirection = glm::vec3(0.0f, 0.0f, 0.0f);
    _cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    _cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    _fov = 45.0f;
    _aspect = (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT;
    _window = WindowContainer::instance().window;

    auto fppActor = BlfWorld::instance().getBlfObjectByTag("FppActor");
    _transform = fppActor->getComponent<Transform>();
  }

  //http://in2gpu.com/2016/02/26/opengl-fps-camera/
  const void update() {
    keyboard();
    mouse();
    updateCameraState();

  }

  void mouse() {
    double x, y;
    glfwGetCursorPos(_window, &x, &y);

    //always compute delta
    //mousePosition is the last mouse position
    glm::vec2 mouse_delta = glm::vec2(x, y) - lastMousePos;

    const float mouseX_Sensitivity = 0.012f;
    const float mouseY_Sensitivity = 0.012f;
    //note that yaw and pitch must be converted to radians.
    //this is done in UpdateView() by glm::rotate
    yaw += mouseX_Sensitivity * mouse_delta.x;
    pitch += mouseY_Sensitivity * mouse_delta.y;

    //
    if (pitch > 89.0f)
      pitch = 89.0f;
    if (pitch < -89.0f)
      pitch = -89.0f;

    lastMousePos = glm::vec2(x, y);
  }

  void keyboard() {
    float dx = 0;
    float dz = 0;

    float up_down = 0;

    if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
      dz = 1;
    }
    else if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
      dz = -1;
    }

    if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
      dx = -1;
    }
    else if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
      dx = 1;
    }

    if (glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_PRESS) {
      up_down = 1;
    }

    glm::mat4 mat = _view;
    //row major
    glm::vec3 forward(mat[0][2], mat[1][2], mat[2][2]);
    glm::vec3 strafe(mat[0][0], mat[1][0], mat[2][0]);

    const float speed = 0.025f;//how fast we move

                              //forward vector must be negative to look forward. 
                              //read :http://in2gpu.com/2015/05/17/view-matrix/
    _transform->position += (-dz * forward + dx * strafe) * speed;

    _transform->position.z += up_down * speed;
  }

  void updateCameraState() {
    glm::mat4 matRoll = glm::mat4(1.0f);//identity matrix; 
    glm::mat4 matPitch = glm::mat4(1.0f);//identity matrix
    glm::mat4 matYaw = glm::mat4(1.0f);//identity matrix

                                       //roll, pitch and yaw are used to store our angles in our class
    matRoll = glm::rotate(matRoll, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));//roll
    matPitch = glm::rotate(matPitch, pitch, glm::vec3(1.0f, 0.0f, 0.0f));
    matYaw = glm::rotate(matYaw, yaw, glm::vec3(0.0f, 1.0f, 0.0f));

    //order matters
    glm::mat4 rotate = matRoll * matPitch * matYaw;

    glm::mat4 translate = glm::mat4(1.0f);
    translate = glm::translate(translate, -(_transform->position));

    _view = rotate * translate;
    _projection = glm::perspective(_fov, _aspect, 0.1f, 100.0f);

    // cout << "pitch: " << pitch << ", yaw:" << yaw << endl;
  }

 /* void changeLookDirection(glm::vec3 delta) {
    _lookDirection += delta;
  }*/

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
  float yaw = 100.0f;
  float pitch = 80.0f;

  float mouseSensitivity = 0.15f;


private:
  glm::mat4 _view;
  glm::mat4 _projection;
  glm::vec3 _cameraUp;
  glm::vec3 _lookDirection;
  glm::vec2 lastMousePos;

  GLfloat _fov;
  GLfloat _aspect;
  Transform* _transform;
  GLFWwindow* _window;
};