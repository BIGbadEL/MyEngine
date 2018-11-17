//
// Created by grzegorz on 17.11.18.
//


#include "Window.h"

namespace GL{

    Window::Window( int width, int height, const char *name):  _width(width), _height(height), _Window(nullptr), _name(name) {
        if(glfwInit() != GLFW_TRUE){
            //TODO: logging system
            return;
        }
        _Window = glfwCreateWindow(_width, _height, _name, nullptr, nullptr);



        if(_Window == nullptr){
            //TODO logging system
            return;
        }

        glfwMakeContextCurrent(_Window);
        glfwSetWindowUserPointer(_Window, this);

        if(glewInit() != GLEW_OK){
            //TODO: logging
            return;
        }
        glViewport(0, 0, _width, _height);
        std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl; //TODO: move to logging system

    }

    Window::~Window() {
        glfwDestroyWindow(_Window);
        glfwTerminate();

    }

    void Window::WindowUpdate() const {
        glfwPollEvents();
        glfwSwapBuffers(_Window);
        GLenum error = glGetError();
        if(error != GL_NO_ERROR){
            //TODO: logging
        }
    }
}