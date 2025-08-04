### Setup CMake ###

cmake_minimum_required(VERSION 3.15)
message("-- Hello!")

set(CXX_STANDARD 17)
message("-- Setting C++ standard ${CXX_STANDARD}")

### Setup project ###

project(
    RenderingLab
    VERSION 1.0
    LANGUAGES C CXX)

message("-- Creating project")
message("   with name ${CMAKE_PROJECT_NAME}")
message("   with version ${CMAKE_PROJECT_VERSION}")
message("   with languages ${CMAKE_PROJECT_LANGUAGES}")

# Sets the location of the .cmake scripts
set(CMAKE_MODULE_PATH
        ${PROJECT_SOURCE_DIR}/buildscripts
        ${CMAKE_MODULE_PATH}
        )

message("-- Setting .cmake scripts location")
message("   to ${CMAKE_MODULE_PATH}")

### Get third-party dependencies ###

message("-- Getting system dependencies...")
include(GetSystemDependencies)
message("-- Including setup_module and finish_module macros...")
include(ModuleSetup)

# Add application code

message("-- Setting application's global include directories")
include_directories(
        ${PROJECT_BINARY_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}

        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/thirdparty/glad/include
        ${PROJECT_SOURCE_DIR}/thirdparty/skia/skia
)

message("-- Adding subdirectory: thirdparty")
add_subdirectory(thirdparty)

message("-- Adding subdirectory: src")
add_subdirectory(src)

message("-- Adding subdirectory: app")
add_subdirectory(app)

