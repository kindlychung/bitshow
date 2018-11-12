cmake_minimum_required(VERSION 2.8)
project(bitshow CXX)

# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "*.cpp")

add_library(bitshow ${SOURCES})
