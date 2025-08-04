# An script which gets the system (third-party) dependencies from the package manager

set(APP_DEPENDENCIES glfw)

foreach(dependency IN LISTS SYSTEM_DEPENDENCIES)
        find_package(${dependency} REQUIRED)
endforeach()
