message("-- Generated shared library")
message("   from target Engine")
message("   in ${SKIA_BUILD_DIR}/libskia.friction.so")
message("-- Moving libskia.friction.so")
message("   to ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")

file(COPY ${SKIA_BUILD_DIR}/libskia.friction.so
     DESTINATION ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
