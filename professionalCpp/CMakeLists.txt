cmake_minimum_required(VERSION 3.0.0)
project(professionalCpp VERSION 0.1.0)

add_subdirectory(23_MultithreadedProgramming)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
