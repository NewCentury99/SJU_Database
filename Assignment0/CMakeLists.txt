cmake_minimum_required(VERSION 3.22)
project(Assignment1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=UTF8")

add_executable(Assignment1 main.cpp FileManager.cpp FileManager.h ConsoleUI.cpp ConsoleUI.h)
