cmake_minimum_required(VERSION 3.5)
project(kiki_api C)

set(CMAKE_C_STANDARD 11)

add_library(kiki_api
        kiki_api.c)

add_executable(kiki_test
        kiki_test.c)
target_link_libraries(kiki_test kiki_api)