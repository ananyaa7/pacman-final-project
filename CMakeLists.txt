

cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
project(final_project_ananyaa7)

# This tells the compiler to not aggressively optimize and
# to include debugging information so that the debugger
# can properly read what's going on.
set(CMAKE_BUILD_TYPE Debug)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Warning flags
if(MSVC)
    # warning level 3 and all warnings as errors
    add_compile_options(/W3 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wpedantic -Werror)
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# FetchContent_MakeAvailable was not added until CMake 3.14
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()

# The library code is here.
add_subdirectory(src)

# The Cinder executable code is here.
add_subdirectory(apps)

# The tests are here.
add_subdirectory(tests)

############## Third-party Libraries #####################

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.x
)

# Database library
FetchContent_Declare(
        sqlite-modern-cpp
        GIT_REPOSITORY https://github.com/SqliteModernCpp/sqlite_modern_cpp.git
        GIT_TAG a0f96c10f04d96ccea1b8a49d5998c96e7887bf4
)

# Command-line parsing library
FetchContent_Declare(
        gflags
        GIT_REPOSITORY https://github.com/gflags/gflags.git
        GIT_TAG        v2.2.2
)

FetchContent_Declare(
        sqlite3
        GIT_REPOSITORY https://github.com/alex85k/sqlite3-cmake.git
        GIT_TAG v3.24.0
)

# Adds Catch2 testing library
FetchContent_GetProperties(catch2)
if(NOT catch2_POPULATED)
    FetchContent_Populate(catch2)
    add_library(catch2 INTERFACE )
    target_include_directories(catch2 INTERFACE ${catch2_SOURCE_DIR}/single_include)
endif()

# Adds sqlite_modern_cpp.
FetchContent_GetProperties(sqlite-modern-cpp)
if (NOT sqlite-modern-cpp_POPULATED)
    FetchContent_Populate(sqlite-modern-cpp)
    add_library(sqlite-modern-cpp INTERFACE)
    target_include_directories(sqlite-modern-cpp INTERFACE ${sqlite-modern-cpp_SOURCE_DIR}/hdr)
endif ()

# Adds gflags::gflags
FetchContent_GetProperties(gflags)
if(NOT gflags_POPULATED)
    FetchContent_Populate(gflags)
    add_subdirectory(${gflags_SOURCE_DIR} ${gflags_BINARY_DIR})
endif()

# Adds sqlite3
FetchContent_GetProperties(sqlite3)
if (NOT sqlite3_POPULATED)
    FetchContent_Populate(sqlite3)
    add_subdirectory(${sqlite3_SOURCE_DIR} ${sqlite3_BINARY_DIR})
    target_include_directories(sqlite3 INTERFACE ${sqlite3_SOURCE_DIR}/src)
endif ()



#if(MSVC)
    #set_property(TARGET gas-simulation-test APPEND_STRING PROPERTY LINK_FLAGS " /SUBSYSTEM:CONSOLE")
#endif()

