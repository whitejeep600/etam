cmake_minimum_required(VERSION 3.21)
project(etam)

set(CMAKE_CXX_STANDARD 20)

add_executable(etam src/main.cpp src/Image.h src/Image.cpp src/readers.h src/readers.cpp src/constants.h src/Dataset.cpp src/Dataset.h src/Pattern.cpp src/Pattern.h)
