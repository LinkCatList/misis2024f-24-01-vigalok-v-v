cmake_minimum_required(VERSION 3.10) 
project(MyProject)                   

set(CMAKE_CXX_STANDARD 23)            
set(CMAKE_CXX_STANDARD_REQUIRED True)  


add_executable(MyExecutable rational.cpp rational.hpp main.cpp)

include_directories(${PROJECT_SOURCE_DIR})