cmake_minimum_required(VERSION 3.22)
project(exercise)
set(CMAKE_CXX_STANDARD 17)
# aux_source_directory(./src DIR_SRCS)
# add_executable(demo ${DIR_SRCS})
include_directories(src)
add_subdirectory(src)
add_subdirectory(test)