cmake_minimum_required(VERSION 3.21...3.25 FATAL_ERROR)

project(docs LANGUAGES NONE VERSION 0.0.1)

add_custom_target(${PROJECT_NAME})

# copy the readme.md into the build dir as a mock of building the docs.
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/readme.md ${CMAKE_CURRENT_BINARY_DIR}/docs/docs.md)
