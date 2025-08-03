### Setup CMake ###

cmake_minimum_required(VERSION 3.15)

set(CXX_STANDARD 17)

### Setup project ###

project(
    RenderingLab
    VERSION 1.0
    LANGUAGES C CXX)

# Set CMAKE_MODULE_PATH so cmake can find the scripts
set(CMAKE_MODULE_PATH
        ${PROJECT_SOURCE_DIR}/buildscripts
        ${CMAKE_MODULE_PATH}
        )

### Get third-party dependencies ###

include(ModuleSetup)
include(GetDependencies)

# Add application code

add_subdirectory(src)
add_subdirectory(app)
