cmake_minimum_required(VERSION 3.0)
project(weight)

add_library(
	HX711
	HX711.cpp
	HX711.h
	)

add_executable(Weight main.cpp)
target_link_libraries(Weight PRIVATE HX711)
target_link_libraries(Weight PRIVATE wiringPi)




