macro(setup_module name)
        set(MODULE_NAME ${name})
        unset(MODULE_INCLUDES) # module's include paths
        unset(MODULE_FILES) # module's files
endmacro()

macro(finish_module)
        message("-- Creating library ${MODULE_NAME}")
        add_library(${MODULE_NAME} SHARED)

        message("   with files: ${MODULE_FILES}")
        target_sources(${MODULE_NAME} PRIVATE ${MODULE_FILES})

        message("   with include directories ${MODULE_INCLUDES}")
        include_directories(PRIVATE ${MODULE_INCLUDES})

endmacro()

