#include "BlfWorld.h"

using namespace std;

const GLuint WIDTH = 800, HEIGHT = 600;

BlfWorld* BlfWorld::_instance;

BlfWorld* BlfWorld::instance() {
  if (_instance == NULL) {
    _instance = new BlfWorld();
  }

  return _instance;
}

int BlfWorld::init() const {
  if (glfwInit() != GL_TRUE) {
    cout << "GLFW initialization failed" << endl;
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  try {
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "GKOM - OpenGL 01", nullptr, nullptr);

    if (window == nullptr)
      throw exception("GLFW window not created");

    glfwMakeContextCurrent(window);
//    glfwSetKeyCallback(window, key_callback);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
      throw exception("GLEW Initialization failed");

    glViewport(0, 0, WIDTH, HEIGHT);

    while (!glfwWindowShouldClose(window)) {
      // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
      glfwPollEvents();

      // Clear the colorbuffer
      glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      // Swap the screen buffers
      glfwSwapBuffers(window);
    }
  }

  catch (exception ex) {
    cout << ex.what() << endl;
  }

  glfwTerminate();
}
