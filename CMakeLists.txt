cmake_minimum_required(VERSION 3.8)
project(cs3358_abm_assignment5p2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Assign05P2.cpp
        cnPtrQueue.cpp
        cnPtrQueue.h
        nodes_LLoLL.cpp
        nodes_LLoLL.h)

add_executable(cs3358_abm_assignment5p2 ${SOURCE_FILES})