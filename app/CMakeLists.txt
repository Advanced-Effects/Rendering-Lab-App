add_executable(${CMAKE_PROJECT_NAME} main.cpp)

# Finally join our libraries with the executable
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${APP_LIBRARIES})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        ${PROJECT_BINARY_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}

        ${PROJECT_SOURCE_DIR}/src

        ${APP_INCLUDE_PATHS}
)

