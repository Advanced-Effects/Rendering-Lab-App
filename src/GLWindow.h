#pragma once

#include <string>
#include <vector>
#include <functional>

class GLFWwindow;

class GLWindow {
public:
        GLWindow();
        GLWindow(int width, int height);
        ~GLWindow();

        void setTitle(std::string title);
        void setDimensions(int width, int height);
        void setPosition(int x, int y);
        void setFrameless(bool frameless);

        std::string title() const;
        int width() const;
        int height() const;
        int x() const;
        int y() const;

        // Initializes the glContext (glfwWindow)
        void init();
        GLFWwindow *glContext();

        // We don't want to immediately close the program after creating the window
        int run();

        // Set callbacks of when it's okay to draw things on screen
        void setOnDrawRequest(std::function<void()> callback) {
            m_onDrawRequest.push_back(callback);
        };

private:
        std::string m_title = "Rendering Lab";
        int m_width = 1280;
        int m_height = 720;
        int m_x = 0;
        int m_y = 0;

        /* ********* GLFW ************ */

        // The glContext
        GLFWwindow *m_glfwWindow = nullptr;

        /* ********** Rendering loop ** */

        // Receive input from OpenGL
        void processInput(GLFWwindow *window);
        // Called when it is okay to draw things on screen
        std::vector<std::function<void()>> m_onDrawRequest;

        /* ********** Utility ********** */

        // Helper function to perform useful things to GLFW window
        void attachEvents(GLFWwindow *window);
};
