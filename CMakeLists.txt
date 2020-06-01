cmake_minimum_required(VERSION 3.0)
project(HUEmessage)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

set(SRCS
	"./sources/main.cpp"
	"./sources/hueConverter.cpp"
	"./sources/image.cpp"
)

set(HDRS
	"./headers/pixel.hpp"
	"./headers/hueConverter.hpp"
	"./headers/image.hpp"
)

add_executable(main ${HDRS} ${SRCS})

target_compile_options(main PUBLIC "-Wall")
