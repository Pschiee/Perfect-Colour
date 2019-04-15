cmake_minimum_required(VERSION 3.0)
project(Test_Motor)

add_library(
	Motor
	Motor.cpp
	Motor.h
	)

add_executable(Test_Motor motor_test.cpp)
target_link_libraries(Test_Motor PRIVATE Motor)
target_link_libraries(Test_Motor PRIVATE wiringPi)




