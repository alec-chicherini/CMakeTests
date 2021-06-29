cmake_minimum_required(VERSION 3.8)
project(CMAKE_PROJECT_1)

set(SOURCE_EXE CMakeProject1.cpp)
set(SOURCE_LIB foo.cpp)

add_library(foo STATIC ${SOURCE_LIB})

add_executable(project1 ${SOURCE_EXE})

target_link_libraries(project1 foo)


