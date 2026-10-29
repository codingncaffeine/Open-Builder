cmake_minimum_required(VERSION 3.25)
project(obcmp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

find_package(zydis REQUIRED)

add_executable(obcmp obcmp.cpp)
target_link_libraries(obcmp PRIVATE Zydis::Zydis)
target_compile_options(obcmp PRIVATE -Wall -Wextra -Wpedantic)

add_executable(obsig obsig.cpp)
target_link_libraries(obsig PRIVATE Zydis::Zydis)
target_compile_options(obsig PRIVATE -Wall -Wextra -Wpedantic)

add_executable(obclass obclass.cpp)
target_link_libraries(obclass PRIVATE Zydis::Zydis)
target_compile_options(obclass PRIVATE -Wall -Wextra -Wpedantic)

add_executable(obdecl obdecl.cpp)
target_compile_options(obdecl PRIVATE -Wall -Wextra -Wpedantic)

add_executable(obshape obshape.cpp)
target_link_libraries(obshape PRIVATE Zydis::Zydis)
target_compile_options(obshape PRIVATE -Wall -Wextra -Wpedantic)
