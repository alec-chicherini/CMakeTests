cmake_minimum_required(VERSION 3.8)
project(CMAKE_PROJECT_TIMEDELAY)

set(SOURCE_EXE timedelay_example.cpp)

add_executable(project_timedelay ${SOURCE_EXE})

include(FetchContent)

FetchContent_Declare(
td_git
GIT_REPOSITORY https://github.com/ikvasir/timedelay.git
GIT_TAG master
)

FetchContent_MakeAvailable(td_git)

set(TD_INCLUDE ${CMAKE_SOLUTION_SOURCE_DIR}/include/timedelay/)

file(
GLOB ALL_HEADES_AND_CPP
${td_git_SOURCE_DIR}/*.h
${td_git_SOURCE_DIR}/*.cpp

)

file(
     COPY ${ALL_HEADES_AND_CPP}
     DESTINATION ${TD_INCLUDE}
     )

message(
STATUS ${ALL_HEADES_AND_CPP} " COPY TO "
${CMAKE_SOLUTION_SOURCE_DIR}/include/timedelay/)

include_directories(${CMAKE_SOLUTION_SOURCE_DIR}/timedelay)
