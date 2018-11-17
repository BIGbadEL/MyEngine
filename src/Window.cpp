//
// Created by grzegorz on 17.11.18.
//


#include "Window.h"
#include "Log.h"

namespace GL{

    Window::Window( int width, int height, const char *name):  _width(width), _height(height), _Window(nullptr), _name(name) {

        Log::Init();
        CORE_LOG_INFO("Initializing glfw");

        if(glfwInit() != GLFW_TRUE){
            CORE_LOG_ERROR("Could not initialize glfw");
            return;
        }

        CORE_LOG_INFO("Glfw initialized successfully");

        CORE_LOG_INFO("Creating Window");

        _Window = glfwCreateWindow(_width, _height, _name, nullptr, nullptr);

        if(_Window == nullptr){
            CORE_LOG_ERROR("Could not create window");
            return;
        }

        CORE_LOG_INFO("Window created successfully");

        glfwMakeContextCurrent(_Window);
        glfwSetWindowUserPointer(_Window, this);

        CORE_LOG_INFO("Initializing glew");

        if(glewInit() != GLEW_OK){
            CORE_LOG_ERROR("Could not initialize glew");
            return;
        }

        CORE_LOG_INFO("Glfw initialized successfully");

        std::string info("OpenGL: ");
        info.append((char*)glGetString(GL_VERSION));

        CORE_LOG_INFO(info);

        glViewport(0, 0, _width, _height);


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