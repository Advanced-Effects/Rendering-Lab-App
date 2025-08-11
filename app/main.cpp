#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GLUtil.h"
#include "GLWindow.h"
#include "ExampleCanvas.h"

int main(int argc, char *argv[]) {
        std::cout << "- Hello!" << std::endl;

        std::cout << "- Initializing GLFW library..." << std::endl;
        if(!initializeGLFW()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return -1;
        };

        std::cout << "- Create blank OpenGL Window" << std::endl;
        std::cout << "  for GPU rendering" << std::endl;
        GLWindow window;
        window.init();

        std::cout << "- Create and bind Skia to the GLWindow" << std::endl;
        std::cout << "  and draw stuff" << std::endl;
        auto canvas = ExampleCanvas(&window);

        std::cout << "- Running application loop" << std::endl;
        std::cout << "  we don't want the app to immediately close after running" << std::endl;
        return window.run();
}
