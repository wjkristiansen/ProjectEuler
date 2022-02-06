cmake_minimum_required(VERSION 3.21)

project(project_euler
    VERSION 1.0
    DESCRIPTION "Project Euler")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(IN_COMMAND_TEST OFF)

include(FetchContent)
FetchContent_Declare(
  InCommand
  GIT_REPOSITORY https://github.com/wjkristiansen/InCommand.git
  GIT_TAG 2b07c426d5b8a37254f1d9ace37af931a9cf2252
)

FetchContent_MakeAvailable(InCommand)

include_directories(
    src
    inc
    ${InCommand_SOURCE_DIR}/inc)

add_subdirectory(src)
