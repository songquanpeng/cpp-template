cmake_minimum_required(VERSION 3.0)
project(cpp_template)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

aux_source_directory(src SRC)

add_executable(template ${SRC})
