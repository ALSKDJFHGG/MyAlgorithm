cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(algorithm VERSION 0.0.1 LANGUAGES CXX)
enable_testing()
add_subdirectory(src)