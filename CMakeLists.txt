cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(s001/)
add_subdirectory(s002/)
add_subdirectory(s003/)
add_executable(main main.cpp s002/s002.cpp)