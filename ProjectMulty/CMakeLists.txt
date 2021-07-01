#multiple files exampel where dependensy important
cmake_minimum_required(VERSION 3.8)

project("project_multy" CXX)

add_executable(project_m main.cpp)


#add_library(A A.h)
add_library(B B.cpp)
#add_library(C C.h)

#set_target_properties(C project_m PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(project_m B)
