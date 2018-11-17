cmake_minimum_required(VERSION 3.12)
project(MyEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/vendor)
include_directories(${CMAKE_SOURCE_DIR}/vendor/spdlog/include/)

add_library(MyEngine src/Window.cpp src/Window.h src/Log.cpp src/Log.h MyEngine.h)

target_link_libraries(MyEngine GLEW glfw3 GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m pthread dl)