#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GLUtil.h"
#include "GLWindow.h"
#include "ExampleCanvas.h"

int main(int argc, char *argv[]) {
        GLUtil::initializeGLFW();

        GLWindow window;

        auto canvas = ExampleCanvas(&window);

        // We don't want the app to immediately close after running
        return window.run();
}

