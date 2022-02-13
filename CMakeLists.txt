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
  GIT_TAG InCommand.1.0.0.2
)

FetchContent_MakeAvailable(InCommand)

include_directories(
    src
    inc
    ${InCommand_SOURCE_DIR}/inc)

add_subdirectory(src)
