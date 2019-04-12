#pragma once

/**
 * @file Motor.h
 * @author Callum Mason
 * @brief The class Motor provides the functionality to rotate the paints to the appropriate position
 * @date 2019-03-02
 *
 * @copyright Copyright (c) 2019
 *
 */

class Motor {

public:

	/**
		 * @brief Motor object constructor
		 */
	Motor();

	/**
	   * @brief Initialises the motor
	   *
	   * @param input1 The wiringPi pin number for the pin connected to input 1 of the L298.
	   * @param input2 The wiringPi pin number for the pin connected to input 2 of the L298.
	   * @param input3 The wiringPi pin number for the pin connected to input 3 of the L298.
	   * @param input4 The wiringPi pin number for the pin connected to input 4 of the L298.
	   * @param firstenable The wiringPi pin number for the pin connected to EnableA of the L298.
	   * @param secondenable The wiringPi pin number for the pin connected to EnableB of the L298.
	   * @param speed The wiringPi pin number for the pin connected to EnableB of the L298.
	   */

	void init(int input1, int input2, int input3, int input4, int firstenable, int secondenable, int speed);

	/**
	   * @brief Roates the sensor 72 degrees.
	   */
  void rotate();

private:
	//gpio connections
	int pin1;  //pin for input 1 of L298
	int pin2;  //pin for input 2 of L298
	int pin3;  //pin for input 3 of L298
	int pin4;  //pin for input 4 of L298
	int enableA;   //pin for EnableA of L298
	int enableB;  //pin for EnableB of L298
	int time;   //Delay used to speed up or slow down the turn 

	/**
	   * @brief Roates the sensor 18 degrees.
	   */
	void step1();

	/**
	   * @brief Roates the sensor 18 degrees.
	   */
	void step2();

	/**
	   * @brief Roates the sensor 18 degrees.
	   */
	void step3();

	/**
	   * @brief Roates the sensor 18 degrees.
	   */
	void step4();
};
