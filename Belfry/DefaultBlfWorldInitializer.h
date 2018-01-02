#pragma once

#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "BlfWorldInitializer.h"
#include "BlfObjectFactoryManager.h"

class DefaultBlfWorldInitializer : public BlfWorldInitializer {

public:
  void init(BlfWorld* world) {
    initDependencies();

    world->add(blfObjectFactoryManager->newInstanceFrom<WindowContainerFactory>());
    //world->add(blfObjectFactoryManager->newInstanceFrom<FppActorFactory>());
    world->add(blfObjectFactoryManager->newInstanceFrom<CubeFactory>());
  }

private:
  void initDependencies() {
    if (glfwInit() != GL_TRUE)
      throw exception("GLFW initialization failed");

    glewExperimental = GL_TRUE;

    //niezla lipa - do wywalenia jakos na pewno
    auto _window = glfwCreateWindow(1, 1, "empty", nullptr, nullptr);

    if (_window == nullptr)
      throw exception("GLFW window not created");

    glfwMakeContextCurrent(_window);

    if (glewInit() != GLEW_OK)
      throw exception("GLEW Initialization failed");

    glfwSetWindowShouldClose(_window, GL_TRUE);
  }
};