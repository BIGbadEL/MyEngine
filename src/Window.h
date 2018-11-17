//
// Created by grzegorz on 17.11.18.
//
#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace GL {
    /**
     * @class Window
     * @brief class that keeps together information about application and about Window
     */
    class Window {
    public:

        /**
         * @fn Window
         * @brief Initialise glfw, glew and create Window Object
         * @param height -> height of a window
         * @param width -> width of a window
         * @param name -> name of a window
         */

        Window( int width, int height, const char* name);

        /**
         * @fn ~Window
         * @brief destructor of Window class and glfwTerminate
         */

        ~Window();

        /**
         * @fn WindowUpdate
         * @brief update window once per frame
         */

        void WindowUpdate() const;

        /**
         * @fn WindowShouldClose
         * @brief check if window should close
         * @return true if window  should close and false if it shouldn't
         */

        inline bool WindowShouldClose() const{ return (bool)glfwWindowShouldClose(_Window); }

        /**
         * @fn Clear
         * @brief clear color buffer bit
         */

        inline void Clear() const{ glClear(GL_COLOR_BUFFER_BIT); }


    private:
        int _width; /**< width of a Window */
        int _height; /**< height of a Window */
        GLFWwindow* _Window; /** Window Pointer */
        const char* _name; /** title of a Window */
    };

}

