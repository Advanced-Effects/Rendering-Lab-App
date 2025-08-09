#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GLUtil.h"
#include "GLWindow.h"
#include "ExampleCanvas.h"

using namespace std;

int main(int argc, char *argv[]) {
        cout << "- Hello!" << endl;

        cout << "- Initializing GLFW library..." << endl;
        initializeGLFW();

        cout << "- Create blank OpenGL Window" << endl;
        cout << "  for GPU rendering" << endl;
        GLWindow window;

        cout << "- Create and bind Skia to the GLWindow" << endl;
        cout << "  and draw stuff" << endl;
        auto canvas = ExampleCanvas(&window);

        cout << "- Running application loop" << endl;
        cout << "  we don't want the app to immediately close after running" << endl;
        return window.run();
}

