cmake_minimum_required(VERSION 3.21...3.25 FATAL_ERROR)

project(grwe LANGUAGES NONE VERSION 0.0.1)

# enable C++
include(CheckLanguage)
check_language(CXX)
if(CMAKE_CXX_COMPILER STREQUAL NOTFOUND)
    message(FATAL_ERROR "No CXX compiler found. aborting.")
endif()
enable_language(CXX)

option(GRWE_LIBOPT_A "Enable option A for the GRWE library" ON)
option(GRWE_LIBOPT_B "Enable option B for the GRWE library" OFF)

set(GRWE_LIB_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/../include/grwe/grwe.h)
set(GRWE_LIB_SRC ${CMAKE_CURRENT_LIST_DIR}/grwe/grwe.cpp)
set(GRWE_ALL_SRC ${GRWE_LIB_INCLUDE} ${GRWE_LIB_SRC})

add_library(${PROJECT_NAME} STATIC ${GRWE_ALL_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../include")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PUBLIC GRWE_LIBOPT_A="${GRWE_LIBOPT_A}")
target_compile_definitions(${PROJECT_NAME} PUBLIC GRWE_LIBOPT_B="${GRWE_LIBOPT_B}")
