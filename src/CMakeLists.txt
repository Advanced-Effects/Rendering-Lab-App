setup_module(lib${CMAKE_PROJECT_NAME})

set(MODULE_INCLUDES ${PROJECT_SOURCE_DIR}/src)

set(MODULE_FILES
    ${CMAKE_SOURCE_DIR}/src/GLUtil.h
    ${CMAKE_SOURCE_DIR}/src/GLUtil.cpp
    ${CMAKE_SOURCE_DIR}/src/GLWindow.h
    ${CMAKE_SOURCE_DIR}/src/GLWindow.cpp
    ${CMAKE_SOURCE_DIR}/src/ISkiaGLWindow.h
    ${CMAKE_SOURCE_DIR}/src/ISkiaGLWindow.cpp
    ${CMAKE_SOURCE_DIR}/src/ExampleCanvas.h
    ${CMAKE_SOURCE_DIR}/src/ExampleCanvas.cpp
    )

message("   finding where Skia shared library is")
include(FindSkiaSystem)
message("   set SKIA_LIBRARIES to ${SKIA_LIBRARIES}")

# tell target where to find .dlls
target_link_directories(lib${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/src)

set(LIBRARY_DEPENDENCIES
        ${APP_DEPENDENCIES}
        ${SKIA_LIBRARIES}
        glad
)

set(MODULE_LINK ${LIBRARY_DEPENDENCIES})

set(MODULE_CUSTOM_DIRECTORIES ${CMAKE_BINARY_DIR}/src)

finish_module()
