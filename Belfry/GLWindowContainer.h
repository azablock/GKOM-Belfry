#pragma once

#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "BlfComponent.h"

class GLWindowContainer : public BlfComponent {

public:
  const void awake() {
    if (glfwInit() != GL_TRUE)
      throw exception("GLFW initialization failed");

    _windowWidth = 1280;
    _windowHeight = 800;
    _windowTitle = "GKOM - Belfry";
    _window = glfwCreateWindow(_windowWidth, _windowHeight, _windowTitle.c_str(), nullptr, nullptr);

    if (_window == nullptr)
      throw exception("GLFW window not created");

    glfwMakeContextCurrent(_window);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
      throw exception("GLEW Initialization failed");

    glViewport(0, 0, _windowWidth, _windowHeight);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  };

  const void update() {
    //todo glfwWindowShouldClose(_window)
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(_window);
  };

  GLFWwindow* window() const {
    return _window;
  }

private:
  GLFWwindow* _window;
  GLuint _windowWidth;
  GLuint _windowHeight;
  std::string _windowTitle;
};