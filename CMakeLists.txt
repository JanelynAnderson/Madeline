# Project & Executable
cmake_minimum_required(VERSION 3.29.1)
project(Madeline)

set(SOURCES
				src/Skeleton/main.cpp
				src/MCAD/Logger/Logging.cpp
)

set(Boost_INCLUDE_DIR "C:/Program Files/boost/boost_1_85_0")
find_package(Boost 1.85 COMPONENTS REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} ${SOURCES})

# Update Git Modules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS ${PROJECT_SOURCE_DIR}/.git)
				option(GIT_SUBMODULE ON)
				if(GIT_SUBMODULE)
								mesage(STATUS "Submodule update")
								execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
																								WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
																								RESULT_VARIABLE GIT_SUBMOD_RESULT )
								if(NOT GIT_SUBMOD_RESULT_EQUAL "0")
												message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
								endif()
				endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
				message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
				PUBLIC .
)

target_include_directories(${PROJECT_NAME} 
				PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME}
				PUBLIC external/glfw/src
				PUBLIC "C:/Program Files/boost/boost_1_85_0/stage/lib"
)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC
				glfw
)
