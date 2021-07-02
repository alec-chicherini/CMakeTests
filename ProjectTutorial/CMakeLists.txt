cmake_minimum_required(VERSION 3.20)
project(project_tutorial VERSION 0.0.1.320 LANGUAGES C CXX)

#https://habr.com/ru/post/431428/
message("Msg 1" "2" "3")
message(Hello,world!)
message("One \t Two \t Three\n 4 5 6")
message(red;green;blue)

set(VAR "WTF")
message("Is this "${VAR}"?")
message("'VAR2' = [${VAR2}]")

#
option(USE_ANOTHER_LIBRARY "WHAT ABOUT ANOTHER LIBRARY " ON)
if(USE_ANOTHER_LIBRARY)
	message("USE_ANOTHER_LIBRARY = ON")
else()
	message("USE_ANOTHER_LIBRARY = OFF")
endif()

#
set(I 100)
while (${I} STREQUAL 100)
	message("I = ${I}" )
	message("I = '${I}'" )
	set(I 99)
endwhile()

#
set(VAR33 one two three for five c.cpp)
foreach(V ${VAR33})
	message(${V})
endforeach()

foreach(I RANGE 5 11 2)
	message(${I})
endforeach()

#
function(f1 msg)
	set(msgf " f1call" PARENT_SCOPE)
	message(msg ${msgf})
endfunction()

macro(m1 msg)
	set(msgm " m1call")
	message(msg ${msgm})
endmacro()

f1(f1)
m1(m1)
message(${msgf}) #error without PARENT_SCOPE
message(${msgm})

#
function(f2)
	cmake_parse_arguments(F2 "YES;NO" "NUMBER" "COLORS" ${ARGV})
	if(${F2_YES} STREQUAL TRUE)
	message("YES = [${F2_YES}]")
	endif()
	if(${F2_NO} STREQUAL TRUE)
	message("NO =  [${F2_NO}]")
	endif()
    message("NUMBER = [${F2_NUMBER}]")
	message("COLORS = [${F2_COLORS}]")
endfunction()

f2(NO NUMBER 444 COLORS red green blue white black)

#https://habr.com/ru/post/432096/
#
include(CMakeScript1.cmake)
message(${VAR_INSIDE_SCRIPT})

#
add_executable(ProjectTutorial main.cpp)
add_library(library STATIC main2.cpp)
target_link_libraries(ProjectTutorial library)

target_sources(ProjectTutorial PUBLIC main3.cpp)

# not working because of build time
#macro(message_gen)
#	add_custom_target(
#	msg_gen
#     COMMAND ${CMAKE_COMMAND} -E echo "$<TARGET_FILE:ProjectTutorial>")
#endmacro()
#
#message_gen()

#message_gen($<TARGET_EXISTS:ProjectTutorial>) 
#message_gen($<TARGET_EXISTS:library>) 
#	   
#message_gen(RUNTIME_OUTPUT_DIRECTORY)
#message_gen(RUNTIME_OUTPUT_NAME)
#message_gen(LIBRARY_OUTPUT_DIRECTORY)
#message_gen(LIBRARY_OUTPUT_NAME)
#	  
#message_gen($<TARGET_FILE:ProjectTutorial>)
#message_gen($<TARGET_FILE_NAME:ProjectTutorial>)
#message_gen($<TARGET_FILE:library>)
#message_gen($<TARGET_FILE_NAME:library>)


add_custom_target(print
        ${CMAKE_COMMAND} -E 
		echo $<TARGET_EXISTS:ProjectTutorial>
		&& echo $<TARGET_EXISTS:library>
		&& echo $<TARGET_FILE:ProjectTutorial>
		&& echo $<TARGET_FILE_NAME:ProjectTutorial>
		&& echo $<TARGET_FILE:library>
		&& echo $<TARGET_FILE_NAME:library>
    )
#cmake -S. -BBuild -G "Ninja"
#cmake --build . --target print

