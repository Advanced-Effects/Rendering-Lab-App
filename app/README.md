# app/

This is where the application begins!

- The main application's executable is created (`add_executable(RenderingLab main.cpp)`)
- All of the other libraries and dependencies are linked with the main executable (`target_link_libraries`) including `libRenderingLab` (`src/`), `SKIA_LIBRARIES` (buildscripts/FindSkiaSystem.cmake), `glad` (thirdparty/glad/CMakeLists.txt).
- We first **initialize the GLFW** library. Then, we **create an OpenGL window/context** and **bind Skia** to it. Finally, **we keep the application running in a loop** until the user solicits to quit.
