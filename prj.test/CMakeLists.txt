cmake_minimum_required(VERSION 3.15)
project(test)

include(FetchContent)

FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/doctest/doctest.git
  GIT_TAG v2.4.9
)

FetchContent_MakeAvailable(doctest)

add_executable(test rational_doctest.cpp)
include_directories(../prj.lab)
target_link_libraries(test doctest::doctest)
