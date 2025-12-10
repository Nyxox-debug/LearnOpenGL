cmake_minimum_required(VERSION 3.10)
project(LearnOpenGL)

# Suppress Developer Warnings
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories (adjust if glad is elsewhere)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find GLFW
find_package(glfw3 3.3 REQUIRED)

# Add the executable
add_executable(app main.cpp glad.c)

# Link libraries
target_link_libraries(app PRIVATE glfw OpenGL::GL dl)
