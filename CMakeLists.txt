cmake_minimum_required(VERSION 3.0)
project(HUEmessage)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

set(SRCS
        #"./sources/main.cpp"
        #"./sources/pixel.cpp"
        #"./sources/image.cpp"
        "./sources/Color.cpp"
        "sources/testColor.cpp"
)

set(HDRS
        #"./headers/pixel.hpp"
        #"./headers/image.hpp"
        "./headers/Color.hpp"
)

add_executable(main ${HDRS} ${SRCS})

target_compile_options(main PUBLIC "-Wall")
