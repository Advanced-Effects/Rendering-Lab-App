setup_module(glad)

set(GLAD_PATH "${PROJECT_SOURCE_DIR}/thirdparty/glad")
set(SRC_PATH "${GLAD_PATH}/src")

set(MODULE_INCLUDES ${GLAD_PATH}/include)

set(MODULE_FILES
        ${MODULE_INCLUDES}/glad/glad.h
        ${SRC_PATH}/glad.c)

finish_module()
