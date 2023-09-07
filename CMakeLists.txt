cmake_minimum_required(VERSION 3.26)
project(learnWin32)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-D_UNICODE -DUNICODE)
add_executable(learnWin32 WIN32 main.cpp
        WinProc.h)
#add_executable(learnWin32 main.cpp)
