# Rendering Lab App

An application to test (in isolation) the rendering capabilities of Advanced Effects.

## Understand the project

- `app/`: Where the application begins! (`main.cpp`). Come here to see how the application's overall workflow works
- `src/`: Our source code (`libRenderingLab`)
- `thirdparty/`: Where third-party modules reside (`skia` and `glad`)
- `buildscripts/`: Useful CMake scripts (`CMAKE_MODULE_PATH`)

## How to run

### Linux dependencies

You need the typical setup (CMake, Ninja, C++17 compiler, Git...) PLUS this:

```
apt-get install mesa-utils libglu1-mesa-dev freeglut3-dev mesa-common-dev
apt-get install libglew-dev libglfw3-dev libglm-dev
```

### Windows dependencies

- [How to setup GLFW in Windows using Visual Studio](https://learnopengl.com/Getting-started/Creating-a-window).

### Build & run

Clone the repository, setup CMake and build:

```
git clone https://github.com/Advanced-Effects/Rendering-Lab-App.git
cd Rendering-Lab-App
mkdir build && cd build
cmake ..
cmake --build .
```

Run:

```
./RenderingLab
```

