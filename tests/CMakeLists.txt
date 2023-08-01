cmake_minimum_required(VERSION 3.21...3.25 FATAL_ERROR)

project(tests LANGUAGES NONE VERSION 0.0.1)

# enable C++
include(CheckLanguage)
check_language(CXX)
if(CMAKE_CXX_COMPILER STREQUAL NOTFOUND)
    message(FATAL_ERROR "No CXX compiler found. aborting.")
endif()
enable_language(CXX)

# define the binary, include and link options
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/src")
target_link_libraries(${PROJECT_NAME} grwe)

# add the test
include(CTest)
add_test(NAME tests_binary COMMAND ${PROJECT_NAME})
