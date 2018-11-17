cmake_minimum_required(VERSION 3.12)
project(MyEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(MyEngine MyEngine.h src/Window.cpp src/Window.h)

target_link_libraries(MyEngine GLEW glfw3 GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m pthread dl)