# Finds where Skia shared library is depending on the operating system
# SKIA_LIBRARIES: Which libraries to link to

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
