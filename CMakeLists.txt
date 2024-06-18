cmake_minimum_required(VERSION 3.5)

project(Minesweeper VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(EXTERNAL_LIBS "C:/Coding Libraries/C++ Libraries")

# Eigen
set(EIGEN3_INCLUDE_DIR "${EXTERNAL_LIBS}/eigen-3.4.0")
include_directories(${EIGEN3_INCLUDE_DIR})

# GLFW
set(GLFW_DIR "${EXTERNAL_LIBS}/glfw-3.4")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
include_directories(${GLFW_DIR}/include)

# Qt 6
set(Qt6_DIR "C:/Qt/6.7.1/msvc2019_64/lib/cmake/Qt6")
find_package(Qt6 REQUIRED COMPONENTS Core)
include_directories(${Qt6_INCLUDE_DIRS})

# OpenAL
set(OPENAL_INCLUDE_DIR "${EXTERNAL_LIBS}/oalinst/include")
set(OPENAL_LIBRARY "${EXTERNAL_LIBS}/oalinst/lib/OpenAL32.lib")
include_directories(${OPENAL_INCLUDE_DIR})
link_directories(${EXTERNAL_LIBS}/oalinst/lib)

# stb_image
set(STB_INCLUDE_DIR "${EXTERNAL_LIBS}/stb_image")
include_directories(${STB_INCLUDE_DIR})

# Google Test
set(Google_DIR "${EXTERNAL_LIBS}/googletest-main")
include_directories(${Google_DIR}/googletest/include ${Google_DIR}/googlemock/include)

# Add executable
add_executable(Minesweeper src/main.cpp)

# Link libraries
target_link_libraries(Minesweeper PRIVATE glfw OpenAL32 Qt6::Core)

# Add Google Test executable
file(GLOB_RECURSE TEST_SOURCES
    "${CMAKE_SOURCE_DIR}/tests/*.h"
    "${CMAKE_SOURCE_DIR}/tests/*.cpp"
)

add_executable(runTests ${TEST_SOURCES})

# Link Google Test libraries
target_link_libraries(runTests PRIVATE gtest gtest_main)

# Link the project libraries to the test executable
target_link_libraries(runTests PRIVATE glfw OpenAL32 Qt6::Core)
