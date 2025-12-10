#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

int main() {

  // NOTE: First we initialize glfw wit glfwInit() and then set some options for
  // the next window we create with glfwWindowHint
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // NOTE: Next we create the window Object which contains all the window data
  GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  // This function makes the OpenGL context associated with that window
  // “current” for the calling thread. So it gives OpenGL the window to work in
  glfwMakeContextCurrent(window);

  // NOTE: We pass GLAD the function to load the address of the OpenGL function
  // pointers which is OS-specific. GLFW gives us glfwGetProcAddress that
  // defines the correct function based on which OS we're compiling for.
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // NOTE: This tells OpenGL the size of the Rendering Window
  glViewport(0, 0, 800, 600);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // Render Loop, So Program Does not close
  while (!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // NOTE: To properly clean all the resources allocated by GLFW
  glfwTerminate();
  return 0;
}
