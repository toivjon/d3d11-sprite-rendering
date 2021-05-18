# require CMake 3.8 to support C++17 standard target compile features.
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# our project is a simple C++ project for sprite sandboxing.
project(sprites VERSION 1.0.0 LANGUAGES CXX)

# build an executable for the Windows environment.
add_executable(sprites WIN32 main.cpp)

# use C++17 standard support with our compiler.
target_compile_features(sprites PUBLIC cxx_std_17)

# link against Direct3D version 11.
target_link_libraries(sprites d3d11)
