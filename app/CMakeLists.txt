message("-- Creating main executable with target name ${CMAKE_PROJECT_NAME}")
add_executable(${CMAKE_PROJECT_NAME} main.cpp)

# Tell CMake to find .dlls in 'build/src' so it can find libskia.friction.so
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/src)

include(skia/FindSkiaSystem)

set(EXECUTABLE_LIBRARIES
        ${APP_DEPENDENCIES}
        ${SKIA_LIBRARIES}
        glad
        lib${CMAKE_PROJECT_NAME}
)
message("   linked with ${EXECUTABLE_LIBRARIES}")

# Finally join our libraries with the executable
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${EXECUTABLE_LIBRARIES})
