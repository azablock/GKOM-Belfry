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
   /* if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS)
      _transform->position += _movementSpeed * _camera->cameraFront();
    if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS)
      _transform->position -= _movementSpeed * _camera->cameraFront();
    if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS)
      _transform->position -= glm::normalize(glm::cross(_camera->cameraFront(), _camera->cameraUp())) * _movementSpeed;
    if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS)
      _transform->position += glm::normalize(glm::cross(_camera->cameraFront(), _camera->cameraUp())) * _movementSpeed;*/


  }

  void handleMouse() {
  }

  //todo to be removed --------------
  float _movementSpeed; //todo move to other component ei. Movement, which has movementSpeedVector
  // --------------------------------

  Transform* _transform;
  GLFWwindow* _window;
  Camera* _camera;
};