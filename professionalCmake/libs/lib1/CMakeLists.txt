cmake_minimum_required(VERSION 3.0.0)


add_library(lib1 SHARED)
target_sources(lib1 
    PRIVATE
    src/Words.cpp)
target_include_directories(lib1 PUBLIC
inc)

