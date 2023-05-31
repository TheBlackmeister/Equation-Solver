cmake_minimum_required(VERSION 3.23)
project(Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(Equation_Solver)

add_executable(Project
        Equation_Solver/main.cpp
        Equation_Solver/rescource.h
        Equation_Solver/rescources.rcx.c)
