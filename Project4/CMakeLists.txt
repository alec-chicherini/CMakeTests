cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0074 OLD)

project(PROJECT_4)

set(SOURCE_EXE out_lib.cpp)

add_executable(project4 ${SOURCE_EXE})


find_package(Boost)

if(NOT Boost_FOUND)
	message(SEND_ERROR "boost not found.")
	return()
else() 
	include_directories(${Boost_INCLUDE_DIRS})
endif()
