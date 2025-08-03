macro(setup_module name)
        set(MODULE_NAME ${name})
        unset(MODULE_INCLUDES)
        unset(MODULE_FILES)
endmacro()

macro(finish_module)
        # Add include path to include directories
        set(APP_INCLUDE_PATHS
                ${MODULE_INCLUDES}
                ${APP_INCLUDE_PATHS})


        # Create CMake library
        add_library(${MODULE_NAME} ${MODULE_FILES})

        # Add library to list to link it against executable
        set(APP_LIBRARIES
                ${MODULE_NAME}
                ${APP_LIBRARIES})
endmacro()

