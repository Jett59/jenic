cmake_minimum_required(VERSION 3.12)

#Project
project(Jenic VERSION 0.0.1)

#C++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Project config file
configure_file(config/jenic.h jenic_config.h)

#Include directory
set(CMAKE_CXX_FLAGS 
"-I \"${PROJECT_SOURCE_DIR}/include\""
)

add_subdirectory(lib)
add_subdirectory(tools)
