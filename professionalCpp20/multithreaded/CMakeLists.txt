cmake_minimum_required(VERSION 3.0.0)
project(multithread VERSION 0.1.0 LANGUAGES C CXX)
set(CXX_STANDARD 20)
include(CTest)
enable_testing()

add_executable(multithread main.cpp)
set_property(TARGET multithread PROPERTY CXX_STANDARD 20)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
