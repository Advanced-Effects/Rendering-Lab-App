macro(setup_module name)
        set(MODULE_NAME ${name})
        unset(MODULE_INCLUDES) # module's include paths
        unset(MODULE_FILES) # module's files
        unset(MODULE_CUSTOM_DIRECTORIES) # custom directories where to look for .so or .a files (DLLs)
        unset(MODULE_LINK) # module's targets to link against to
endmacro()

macro(finish_module)
        message("-- Creating library ${MODULE_NAME}")
        add_library(${MODULE_NAME} SHARED)

        message("   with files: ${MODULE_FILES}")
        target_sources(${MODULE_NAME} PRIVATE ${MODULE_FILES})

        message("   with include directories ${MODULE_INCLUDES}")
        include_directories(PRIVATE ${MODULE_INCLUDES})

        if (MODULE_CUSTOM_DIRECTORIES)
        target_link_directories(${MODULE_NAME} PRIVATE ${MODULE_CUSTOM_DIRECTORIES})
        message("  find libraries in directories ${MODULE_CUSTOM_DIRECTORIES}")
        endif()

        if (MODULE_LINK)
        target_link_libraries(${MODULE_NAME} PRIVATE ${MODULE_LINK})
        message("  link with libraries ${MODULE_LINK}")
        endif()

endmacro()

