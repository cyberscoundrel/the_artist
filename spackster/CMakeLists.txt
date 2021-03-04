cmake_minimum_required(VERSION 3.12)

set(_projectName "output")
set(CMAKE_PREFIX_PATH "/libs/sdl")

project(${_projectName} VERSION 1.0.0)


#Link source files to executable
add_executable(${_projectName}
../src/main.cpp
)


#SDL
set( SDL_STATIC ON CACHE BOOL "" FORCE )
set( SDL_SHARED OFF CACHE BOOL "" FORCE )
add_subdirectory(libs/sdl/)
target_link_libraries( ${_projectName} SDL2main SDL2-static )

#GLEW
add_subdirectory(libs/glew/build/cmake/)
target_include_directories(${_projectName} PRIVATE libs/glew/include)
target_link_libraries(${_projectName} glew_s)


#GLM
add_subdirectory(libs/glm/)
target_link_libraries(${_projectName} glm)

#Build executable file in sandbox directory
set_target_properties( ${_projectName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/sandbox" )
set_target_properties( ${_projectName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/sandbox" )
set_target_properties( ${_projectName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/sandbox" )
set_target_properties( ${_projectName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_SOURCE_DIR}/sandbox" )
set_target_properties( ${_projectName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/sandbox" )






#Remove console window for application
#set_target_properties(${_projectName} PROPERTIES 
#    LINK_FLAGS "/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS")
