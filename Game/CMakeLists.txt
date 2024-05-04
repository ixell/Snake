cmake_minimum_required (VERSION 3.13 FATAL_ERROR)

target_include_directories (Snake PUBLIC .)
target_sources (Snake
	PRIVATE
		"Snake.cpp"
		"Snake.h"
		"SnakeBlock.cpp"
		"SnakeBlock.h"
		"Apple.cpp"
		"Apple.h"
)
