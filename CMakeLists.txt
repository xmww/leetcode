cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(s001/)
add_subdirectory(s002/)
add_subdirectory(s003/)
add_subdirectory(s004/)
add_subdirectory(s005/)
add_subdirectory(s006/)
add_subdirectory(s007/)
add_subdirectory(s008/)
add_subdirectory(s009/)
add_subdirectory(s010/)
add_subdirectory(s011/)
add_subdirectory(s012/)

add_executable(main s012/s012.cpp)