cmake_minimum_required(VERSION 3.25)
project(obassets LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

find_package(PNG REQUIRED)

add_executable(obdbpf obdbpf.cpp)
target_link_libraries(obdbpf PRIVATE PNG::PNG)
target_compile_options(obdbpf PRIVATE -Wall -Wextra -Wpedantic)
