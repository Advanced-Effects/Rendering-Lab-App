setup_module(glad)

set(GLAD_PATH "${PROJECT_SOURCE_DIR}/thirdparty/glad")

set(MODULE_INCLUDES ${GLAD_PATH}/include)

set(MODULE_FILES
        include/glad/glad.h
        src/glad.c)

message("-- Creating library ${MODULE_NAME}")

add_library(${MODULE_NAME} SHARED)

target_sources(${MODULE_NAME} PRIVATE ${MODULE_FILES})

target_include_directories(${MODULE_NAME} PRIVATE ${MODULE_INCLUDES})

# We install the target to a "system-like location" so we can import it with brackets <>

message("-- Installing glad library to system-like location: ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
message("   so it is includable using brackets (#include <glad/glad.h>)")

set_target_properties(${MODULE_NAME} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}
)
