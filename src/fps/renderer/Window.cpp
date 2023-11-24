/**
 * @file Window.cpp
 * @author Kuriioo
*/

#include <fps/renderer/Window.hpp>
#include <GLFW/glfw3.h>
#include <assert.h>
#include <iostream>


namespace fps 
{
    
  Window::Window()
  {
    assert(m_instance == nullptr && "Already init!");
    m_instance = this; 
    m_context = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle.c_str(), NULL, NULL);
    if (m_context == nullptr) 
    {
      glfwTerminate();
      std::cerr << "Cannot init window!" << std::endl;
      return;
    };
    glfwMakeContextCurrent(m_context); 
  };


  Window::~Window()
  {
    m_instance = nullptr; 
    glfwTerminate();
  };


  void Window::setWindowWidth(int32_t w) 
  {
    m_windowWidth = w;
    glfwSetWindowSize(m_context, m_windowWidth, m_windowHeight);
  };


  void Window::setWindowHeight(int32_t h)
  {
    m_windowHeight = h;
    glfwSetWindowSize(m_context, m_windowWidth, m_windowHeight);
  };


  void Window::setWindowTitle(const std::string t)
  {
    m_windowTitle = t;
    glfwSetWindowTitle(m_context, m_windowTitle.c_str());
  };
};