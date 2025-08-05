message("-- Creating main executable with target name ${CMAKE_PROJECT_NAME}")
add_executable(${CMAKE_PROJECT_NAME} main.cpp)

message("-- Use target_link_directories to")
message("   tell target where to look for .dlls")
message("   (by default in CMake +3 it is recommended to link by targets, not directories)")
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/src)

set(EXECUTABLE_LIBRARIES
        ${APP_DEPENDENCIES}
        ${SKIA_LIBRARIES}
        glad
        lib${CMAKE_PROJECT_NAME}
)
message("   linked with ${EXECUTABLE_LIBRARIES}")

# Finally join our libraries with the executable
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${EXECUTABLE_LIBRARIES})

