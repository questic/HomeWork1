cmake_minimum_required(VERSION 3.0.0)
project(HomeWork1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(HomeWork1 src/main.cpp src/FileIO.h src/FileIO.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
