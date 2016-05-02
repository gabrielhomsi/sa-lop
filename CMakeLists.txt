cmake_minimum_required(VERSION 3.3)
project(untitled)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O3 -lboost_program_options")

set(SOURCE_FILES src/Main.cpp src/Solution.cpp src/Solution.h src/SimulatedAnnealing.cpp src/SimulatedAnnealing.h src/Random.cpp src/Random.h src/Graph.cpp src/Graph.h src/Summary.cpp src/Summary.h src/Parameters.cpp src/Parameters.h)

set(EXECUTABLE_OUTPUT_PATH "release")

add_executable(Main ${SOURCE_FILES})