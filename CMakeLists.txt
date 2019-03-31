cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -pedantic ${CMAKE_CXX_FLAGS}")
include_directories(parser)
include_directories(semant)
include_directories(utils)
include_directories(run1)
project(compler)

set(CMAKE_CXX_STANDARD 11)

add_executable(compler
        parser/moon_parser_bison.cpp
        parser/moon_parser_flex.cpp
        parser/moon_parser.cpp
        parser/syntax_tree.cpp
        semant/type_info.cpp
        semant/frame.cpp
        semant/symbol.cpp
        semant/table.cpp
        semant/translate.cpp
        semant/entry.cpp
        run1/run1.cpp
        parser_test.cpp)