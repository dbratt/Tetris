cmake_minimum_required(VERSION 3.0.0)

project(tetris VERSION 0.1.0)

file(GLOB SOURCE_EXE src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_EXE})
	

