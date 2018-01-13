#pragma once

#include <GLFW/glfw3.h>
#include "Singleton.h"

class WindowContainer : public Singleton<WindowContainer> {
public:
  friend class Singleton<WindowContainer>;

  GLFWwindow* window;
};