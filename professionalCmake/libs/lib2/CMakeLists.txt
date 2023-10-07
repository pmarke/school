cmake_minimum_required(VERSION 3.0.0)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_library(lib2 STATIC)
target_sources(lib2 
    PRIVATE
    src/Math.cpp)
target_link_libraries(lib2 PUBLIC 
Eigen3::Eigen
lib1
)
target_include_directories(lib2 PUBLIC
inc
)

add_executable(main src/main.cpp)
target_link_libraries(main lib2)

