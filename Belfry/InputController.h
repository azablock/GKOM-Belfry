#pragma once

#include <GLFW/glfw3.h>
#include "BlfComponent.h"
#include "WindowContainer.h"

class InputController : public BlfComponent {
public:
  const void awake() {
    auto fppActor = BlfWorld::instance().getBlfObjectByTag("FppActor");
    _transform = fppActor->getComponent<Transform>();
    _camera = fppActor->getComponent<Camera>();
    _window = Singleton<WindowContainer>::instance().window;
    _movementSpeed = 0.02f;
    
    
    //to tez dziala bo mamy w GLWindowContainer glfwPollEvents();
    //  glfwSetCursorPosCallback(_window, mouseMovementCallback);
    //glfwSetKeyCallback(this->_glWindowContainer->window(), handleInput);
  }

  const void update() {
    handleMouse();
    handleKeyboard();
  }

private:
  //static void handleInput(GLFWwindow* window, int key, int scancode, int action, int mode) {
  //  cout << "InputController: key -> " << key << endl;
  //}

  //static void mouseMovementCallback(GLFWwindow* window, double xpos, double ypos) {
  //  
  //}

  void handleKeyboard() {
    if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS)
      _transform->position += _movementSpeed * _camera->cameraFront();
    if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS)
      _transform->position -= _movementSpeed * _camera->cameraFront();
    if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS)
      _transform->position -= glm::normalize(glm::cross(_camera->cameraFront(), _camera->cameraUp())) * _movementSpeed;
    if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS)
      _transform->position += glm::normalize(glm::cross(_camera->cameraFront(), _camera->cameraUp())) * _movementSpeed;
  }

  void handleMouse() {
    glfwGetCursorPos(_window, &cursorX, &cursorY);

    if (firstMouse)
    {
      cursorlastX = cursorX;
      cursorlastY = cursorY;
      firstMouse = false;
    }


    float xoffset = cursorX - cursorlastX;
    float yoffset = cursorY - cursorlastY;
    cursorlastX = cursorX;
    cursorlastY = cursorY;

    float sensitivity = 0.2;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
      pitch = 89.0f;
    if (pitch < -89.0f)
      pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    _camera->_cameraFront = glm::normalize(front);
  }

  //todo to be removed --------------
  float _movementSpeed; //todo move to other component ei. Movement, which has movementSpeedVector
  // --------------------------------

  Transform* _transform;
  GLFWwindow* _window;
  Camera* _camera;

  // yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
  float yaw = -90.0f;
  float pitch = 0.0f;

  double cursorX;
  double cursorY;

  float cursorlastX;
  float cursorlastY;

  float cursorOffsetX;
  double cursorOffsetY;

  bool firstMouse = true;
};