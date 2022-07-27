#cmake version
cmake_minimum_required(VERSION 3.10)

#project name
project(graphs)

#define c++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#define source directories, "include" is for headers and "src" is for implementation
include_directories(
        graphs/include
        graphs/src
)

#define a list, called SRC_FILES, that stores all source code files within "include" and "src"
file(GLOB_RECURSE SRC_FILES
        "graphs/include/*.h"
        "graphs/src/*.cpp"
        )

#include all source code files to generate an executable
add_executable(graphs src/main.cpp
        src/graph/Vertex.cpp
        src/graph/HashFunctions.cpp
        src/graph/Graph.cpp
        src/graph/Edge.cpp
        src/entity/StringElement.cpp
        src/entity/Object.cpp
        src/entity/City.cpp
        src/algorithms/DijkstraOutput.cpp
        src/algorithms/DijkstraAlgorithm.cpp)
