cmake_minimum_required(VERSION 3.0.0)
project(multiThread VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(Threads REQUIRED)

add_executable(multiThread main.cpp)
target_link_libraries(multiThread Threads::Threads)

set(CMAKE_CXX_STANDARD 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
