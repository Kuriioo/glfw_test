cmake_minimum_required(VERSION 3.20)

project(fps CXX)

set(SOURCES src/fps/main.cpp
            src/fps/renderer/Window.cpp)

add_executable(fps ${SOURCES})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw-3.3.8)
target_link_libraries(fps glfw)
target_include_directories(fps PRIVATE include)
