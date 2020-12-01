cmake_minimum_required(VERSION 3.15)
project(mySparse)

set(CMAKE_CXX_STANDARD 14)

add_executable(mySparse main.cpp ObjectData.cpp ObjectData.h Object.cpp Object.h Sparse.cpp Sparse.h)