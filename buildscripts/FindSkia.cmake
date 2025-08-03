setup_module(Engine) # use same name as skia directory to declare CMake target

add_subdirectory(${PROJECT_SOURCE_DIR}/thirdparty/skia)

# DO NOT call finish_module
# because setup is already happening in CMake script
