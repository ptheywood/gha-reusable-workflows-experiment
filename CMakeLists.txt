# Main CMakeLists file, configuring the outer project, with top level options included.
# Min CMake is 3.21 for PROJECT_IS_TOP_LEVEL.
cmake_minimum_required(VERSION 3.21...3.25 FATAL_ERROR)

# Top level project with no languages by default, to allow better detection / lint only builds which wouldn't require a compiler (in theory)
project(GRWE LANGUAGES NONE)


# DEfine some options for the top level cmake. 
option(GRWE_ENABLE_LIB "Enable GRWE Static Library building (src subproject)" ON)
option(GRWE_ENABLE_LINT "Enable GRWE Lint targets." ON)
option(GRWE_ENABLE_DOCS "Enable GRWE Docs building." ON)
option(GRWE_ENABLE_EXAMPLE "Enable GRWE example binary project(s) (example subproject)" ON)
option(GRWE_ENABLE_TESTING "Enable GRWE Tests sub project." ON)

# If linting is enabled, create the target. 
if(GRWE_ENABLE_LINT)
    add_custom_target(lint echo "fake-linting ... done")
endif()

# If the library target is not enabled, stop.
if(NOT GRWE_ENABLE_LIB)
    return()
endif()

# Add the src subdir. Everything else depends on it. 
add_subdirectory(src)

# Optionally add the docs subdir
if(GRWE_ENABLE_DOCS)
    add_subdirectory(docs)
endif()

# Optionally add the docs subdir
if(GRWE_ENABLE_EXAMPLE)
    add_subdirectory(example)
endif()

# Optionally add the docs subdir
if(GRWE_ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()
