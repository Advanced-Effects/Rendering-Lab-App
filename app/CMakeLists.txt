message("-- Creating main executable with target name ${CMAKE_PROJECT_NAME}")
add_executable(${CMAKE_PROJECT_NAME} main.cpp)

if(WIN32)
    set(SKIA_LIBRARIES
        skia
        user32
        opengl32)
    add_definitions(-DSKIA_DLL)
else()
    if(APPLE)
        set(SKIA_LIBRARIES skia)
    else()
        set(SKIA_LIBRARIES skia.friction)
    endif()
endif()

set(EXECUTABLE_LIBRARIES
        ${APP_DEPENDENCIES}
        ${SKIA_LIBRARIES}
        glad
        lib${CMAKE_PROJECT_NAME}
)
message("   linked with ${EXECUTABLE_LIBRARIES}")

# Finally join our libraries with the executable
target_link_libraries(${CMAKE_PROJECT_NAME} ${EXECUTABLE_LIBRARIES})

