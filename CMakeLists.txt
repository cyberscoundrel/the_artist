cmake_minimum_required(VERSION 3.0.0)

project(the_artist)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_FIND_DEBUG_MODE ON)
#set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_BINARY_DIR}/win)
#set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
find_package(OpenGL REQUIRED)


find_package(GLEW REQUIRED)


find_package(SDL2 REQUIRED)

find_package(GLM REQUIRED)

#find_package(Threads REQUIRED)


message(STATUS "hello")
message(STATUS ${SDL2MAIN_LIBRARY})
message(STATUS ${GLEW_DIR})
message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS ${CMAKE_FILES_DIRECTORY})
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (NOT GLEW_FOUND)
	message("ok")
	message(OpenGL "path")
endif()

if(WIN32)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/win)
	message(STATUS "windows")
	message(STATUS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
elseif(UNIX)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/linux)
else()
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/osx)
endif()
add_executable(the_artist WIN32 ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

#target_compile_options(the_artist PUBLIC "-lpthread")
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories( ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${SDL2_INCLUDE_DIR} ${GLM_INCLUDE_DIR})
#include_directories(${SDL2_INCLUDE_DIR})

target_link_libraries(the_artist ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${SDL2MAIN_LIBRARY} ${SDL2_LIBRARY})
#target_link_libraries(the_artist ${SDL2_LIBRARY} ${SDL2MAIN_LIBRARY})


