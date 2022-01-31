cmake_minimum_required(VERSION 3.21)

project(project_euler
    VERSION 1.0
    DESCRIPTION "Project Euler")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    src
    inc)

add_subdirectory(src)