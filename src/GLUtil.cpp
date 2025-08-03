#include "GLUtil.h"

#include <iostream>

// For loading the functions (must be included before any other GL import)
#include <glad/glad.h>
// For using OpenGL
#include <GLFW/glfw3.h>

using namespace GLUtil;

// GLFW is the library which we use to call OpenGL functions
void initializeGLFW() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
};

// OpenGL functions need to be manually found.
// We do this with a library called GLAD
bool loadGLFunctions() {
        int returnCode = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        if (returnCode != 0)
                return false;
        return true;
}

