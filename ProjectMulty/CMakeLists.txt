#multiple files exampel where dependensy important
cmake_minimum_required(VERSION 3.8)

project("project_multy" CXX)

add_executable(project_m main.cpp)



add_library(B B.cpp)




target_link_libraries(project_m B)
