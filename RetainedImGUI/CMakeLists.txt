cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_COMPPILER g++)
set(CMAKE_C_COMPPILER gcc)

project(RetainedImGUI VERSION 0.1.0 LANGUAGES C CXX)

# requires the use of at least C++20.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# tells CMake what build type we should use.
set(CMAKE_BUILD_TYPE Debug)

# sets CMake compiler flags.
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# finds the OpenGL & GLFW packages.
find_package(OpenGL REQUIRED)

# finds all .h and .cpp files. also compiles "glad.c".
file(GLOB_RECURSE SOURCES
    "include/*.h"
    "include/*.hpp"
    "include/*.cpp"
    "src/*.hpp"
    "src/*.cpp"
    "glad.c"
)

# tells CMake to create a .exe file using the specified source files.
add_library(RetainedImGUI ${SOURCES})

# handles include directories and libraries.
target_include_directories(RetainedImGUI PRIVATE "include/" "src/")

set(LIBRARY_PATH "${PROJECT_SOURCE_DIR}/lib")
target_include_directories(RetainedImGUI PUBLIC ${LIBRARY_PATH})

include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(RetainedImGUI ${OPENGL_LIBRARIES} ${LIBRARY_PATH}/libglfw3dll.a)
