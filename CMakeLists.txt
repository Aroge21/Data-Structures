cmake_minimum_required(VERSION 3.27.0)
set(CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe")
set(CMAKE_C_COMPILER "C:/mingw64/bin/gcc.exe")

project(project)

add_executable(${PROJECT_NAME} main.cpp binary.cpp)