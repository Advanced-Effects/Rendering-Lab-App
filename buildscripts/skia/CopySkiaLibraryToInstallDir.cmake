message("-- Generated shared library")
message("   from target Engine")
message("   in ${SKIA_BUILD_DIR}/libskia.friction.so")

message("-- Moving libskia.friction.so")
message("   to ${CMAKE_BINARY_DIR}/src")
message("   so it is importable using \"\"")
include(GNUInstallDirs)
install(
    FILES
    ${SKIA_BUILD_DIR}/libskia.friction.so
    DESTINATION
    src # This installs libskia.friction.so to build/src/libskia.friction.so,
    # which then is found with target_link_directories(${CMAKE_BINARY_SRC}/src)
    # and target_link_libraries(skia.friction)
)
