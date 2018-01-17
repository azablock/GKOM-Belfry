#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "gtest/gtest.h"
#include"DefaultBlfWorldInitializer.h"
#include "BlfWorld.h"
#include "WindowContainer.h"
#include "Contants.h"

#define TEST_MODE_ENABLED false;

#if TEST_MODE_ENABLED
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#endif

void initGLFWContext() {
  if (glfwInit() != GL_TRUE)
    throw exception("GLFW initialization failed");

  glewExperimental = GL_TRUE;

  WindowContainer& windowContainer = WindowContainer::instance();

  windowContainer.window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Belfry", nullptr, nullptr);
  GLFWwindow* window = windowContainer.window;

  if (window == nullptr)
    throw exception("GLFW window not created");

  glfwMakeContextCurrent(window);

  if (glewInit() != GLEW_OK)
    throw exception("GLEW Initialization failed");

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  // chyba niepotrzebne
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // -------------------------

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  glEnable(GL_DEPTH_TEST);
 // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void initBlfWorld() {
  BlfWorld& world = BlfWorld::instance();

  auto worldInitializer = new DefaultBlfWorldInitializer();

  worldInitializer->init(world);
  world.awake();
  worldInitializer->setup();
}

void run() {
  BlfWorld& world = BlfWorld::instance();
  GLFWwindow* window = WindowContainer::instance().window;

  while (world.isAlive()) {
    glfwPollEvents();
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    world.update();
    world.lateUpdate();

    glfwSwapBuffers(window); //openGL thread
  }

  glfwTerminate();
}

#if !TEST_MODE_ENABLED
int main() {

  initGLFWContext();
  initBlfWorld();
  run();

  return 0;
}
#endif