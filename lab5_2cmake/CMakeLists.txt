cmake_minimum_required(VERSION 3.15) 

set(PROJECT_NAME lab5_2CMake)						 
project("${PROJECT_NAME}")			 


set(CMAKE_CXX_STANDARD 17)			 
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
			 

add_executable("${PROJECT_NAME}" lab5_2.cpp)
								 	
								 
file(COPY input.txt DESTINATION "/")
file(COPY output.txt DESTINATION "/")