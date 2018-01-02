#pragma once
#include "BlfComponent.h"
#include "BlfWorld.h"
#include "GLWindowContainer.h"

class InputController : public BlfComponent {
public:
  const void awake() {
    auto world = BlfWorld::instance();
    auto windowContainer = world->getBlfObjectByTag("WindowContainer");
    this->_glWindowContainer = windowContainer->getComponent<GLWindowContainer>();
    
    //to tez dziala bo mamy w GLWindowContainer glfwPollEvents();
    //glfwSetKeyCallback(this->_glWindowContainer->window(), handleInput);
  
    _movementSpeed = 0.05f;
  }

  const void update() {
   /* if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
      cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
      cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
      cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
      cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;*/

    if (glfwGetKey(_glWindowContainer->window(), GLFW_KEY_W) == GLFW_PRESS)
      cout << "W pressed" << endl;
  }

private:
  static void handleInput(GLFWwindow* window, int key, int scancode, int action, int mode) {
    cout << "InputController: key -> " << key << endl;
  }

  const GLWindowContainer* _glWindowContainer;
  float _movementSpeed; //todo move to other component ei. Movement, which has movementSpeedVector
};