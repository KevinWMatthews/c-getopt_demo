cmake_minimum_required(VERSION 3.5.1)

project(arg_parse_getopt VERSION 1.0.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_executable(GetOptDemo
    getopt_demo.c
)

add_executable(GetOptLongDemo
    getopt_long_demo.c
)
