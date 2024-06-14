cmake_minimum_required(VERSION 3.16)

project(minesweeper VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt
if(DEFINED ENV{QTDIR})
    set(QT_DIR $ENV{QTDIR})
else()
    set(QT_DIR "C:/Qt/6.7.1/msvc2019_64")
endif()
set(CMAKE_PREFIX_PATH ${QT_DIR})
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Set source directory
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

# Include directories
include_directories(${SOURCE_DIR})
include_directories("C:/Coding Libraries/C++ Libraries/eigen-3.4.0")
include_directories("C:/Coding Libraries/C++ Libraries/stb_image")
include_directories("C:/Coding Libraries/C++ Libraries/glfw-3.4/include")
include_directories("C:/Coding Libraries/C++ Libraries/SDL-main/include")

# Find libraries
find_library(GLFW_LIBRARY glfw3 PATHS "C:/Coding Libraries/C++ Libraries/glfw-3.4/lib")
find_library(SDL_LIBRARY SDL2 PATHS "C:/Coding Libraries/C++ Libraries/SDL-main/lib")

# Glob source files
file(GLOB_RECURSE SOURCES
    "${SOURCE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

# Add executable
add_executable(minesweeper WIN32 ${SOURCES})

# Link libraries
target_link_libraries(minesweeper PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
target_link_libraries(minesweeper PRIVATE ${GLFW_LIBRARY})
target_link_libraries(minesweeper PRIVATE ${SDL_LIBRARY})
target_link_libraries(minesweeper PRIVATE opengl32)
