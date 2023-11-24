/**
 * @file main.cpp
 * @author Kuriioo
 */

#include <fps/renderer/Window.hpp>
#include <iostream>


int main (int argc, char **argv)
{
  if (!glfwInit())
  {
    std::cerr << "GLFW not init!" << std::endl;
    exit(EXIT_FAILURE);
  }; 

  auto *win { new fps::Window };

  double time { glfwGetTime() };
  int frame { 0 };

  while (!glfwWindowShouldClose(win->getContext()))
  {
    double currentTime { glfwGetTime() };
    frame++;

    if (currentTime - time >= 1.0)
    {
      std::cout << "FPS: " << frame << std::endl;
      frame = 0;
      time = currentTime;
    };

    glfwPollEvents();

    glfwSwapBuffers(win->getContext());
  };

  glfwDestroyWindow(win->getContext());
  glfwTerminate();

  return EXIT_SUCCESS;
};
