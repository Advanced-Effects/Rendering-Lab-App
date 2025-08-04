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

finish_module()
