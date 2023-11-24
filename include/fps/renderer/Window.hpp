/**
 * @file Window.hpp
 * @author Kuriioo
 */

#pragma once


#include <iostream>
#include <string>
#include <GLFW/glfw3.h>


namespace fps 
{

  class Window
  {
  private:
    Window *m_instance { nullptr };
    GLFWwindow *m_context;

    int32_t m_windowWidth  { 1280 };
    int32_t m_windowHeight { 800 };
    std::string m_windowTitle { "Call of mgl" };

  public:
    Window();
    ~Window();

    Window &getInstance() { return *m_instance; };
    
    GLFWwindow *getContext() { return m_context; };

    inline int32_t getWindowWidth() { return m_windowWidth; };
    inline int32_t getWindowHeight() { return m_windowHeight; };
    inline std::string getWindowTitle() { return m_windowTitle; };

    void setWindowWidth(int32_t w);
    void setWindowHeight(int32_t h);
    void setWindowTitle(const std::string t);
  };

};
