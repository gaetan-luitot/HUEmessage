cmake_minimum_required(VERSION 3.0)
project(HUEmessage)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

set(SRCS
        #"./sources/main.cpp"
        #"./sources/pixel.cpp"
        "./sources/Image.cpp"
        "./sources/Color.cpp"
        "./tests/testImage.cpp"
)

set(HDRS
        #"./headers/pixel.hpp"
        "./headers/Image.hpp"
        "./headers/Color.hpp"
)

add_executable(main ${HDRS} ${SRCS})

target_compile_options(main PUBLIC "-Wall")
