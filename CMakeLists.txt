cmake_minimum_required(VERSION 3.13)
project(Garfield)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE sources "src/*.cpp")

add_executable(garfield ${sources})
target_include_directories(garfield PUBLIC
	"include"
	"lib/cxxopts"
)
target_compile_options(garfield PUBLIC -Wall)

install(TARGETS garfield)