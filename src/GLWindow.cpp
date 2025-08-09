#include "GLWindow.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GLUtil.h"

#include <iostream>

GLWindow::GLWindow() {};
GLWindow::GLWindow(int width, int height) {
        setDimensions(width, height);
};
GLWindow::~GLWindow() {};

void GLWindow::setTitle(std::string title) {
        m_title = title;
};
void GLWindow::setDimensions(int width, int height) {
        m_width = width;
        m_height = height;
};
void GLWindow::setPosition(int x, int y) {
        m_x = x;
        m_y = y;
};
void GLWindow::setFrameless(bool frameless) {};

std::string GLWindow::title() const {
        return m_title;
};
int GLWindow::width() const {
        return m_width;
};
int GLWindow::height() const {
        return m_height;
};
int GLWindow::x() const {
        return m_x;
};
int GLWindow::y() const {
        return m_y;
};

GLFWwindow* GLWindow::glContext() {
        return m_glfwWindow;
};

int GLWindow::run() {
        createGLWindow();
        if (m_glfwWindow == nullptr) {
                return -1;
        };

        while(!glfwWindowShouldClose(m_glfwWindow))
        {
                processInput(m_glfwWindow);
                performRendering(m_glfwWindow);

                // Run application loop (avoid closing app)
                glfwSwapBuffers(m_glfwWindow);
                glfwPollEvents();
        };
        glfwTerminate();

        return 0;
};

void GLWindow::createGLWindow() {
        auto *window = glfwCreateWindow(
                width(),
                height(),
                title().c_str(),
                NULL,
                NULL
        );
        if (window == NULL) {
                std::cerr << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                return;
        }

        // This makes it so that when you call OpenGL functions like glViewport, glClearColor...
        // it affects this window
        glfwMakeContextCurrent(window);

        // Load GL functions AFTER setting the current context
        // Either we're getting a segmentation fault...
        loadGLFunctions();

        m_glfwWindow = window;
};

// Resize the GL Viewport when resizing the window
void onResize(GLFWwindow *window, int width, int height) {
        glViewport(0, 0, width, height);
};

void GLWindow::attachEvents(GLFWwindow *window) {
        // Attatch resize window event
        glfwSetFramebufferSizeCallback(m_glfwWindow, onResize);
};

void GLWindow::processInput(GLFWwindow *window) {};

void GLWindow::performRendering(GLFWwindow *window) {};


