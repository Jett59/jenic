cmake_minimum_required(VERSION 3.10)

#Project
project(Jenic VERSION 0.0.1-SNAPSHOT)

#C++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Project config file
configure_file(config/jenic.h jenic_config.h)

#Include directories
target_include_directories(jenic PUBLIC
"${PROJECT_BINARY_DIR}"
)