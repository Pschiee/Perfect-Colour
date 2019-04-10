#include <wiringPi.h>
#include "Motor.h"

//Constructor
Motor::Motor(){}

/*
	Function to initiliase the pins on the pi that connect to the inputs and enables of the L298. Also sets the speed for totation
*/

void Motor::init(int input1, int input2, int input3, int input4, int firstenable, int secondenable, int speed) {
	wiringPiSetup();
	pin1 = input1;
	pin2 = input2;
	pin3 = input3;
	pin4 = input4;
	time = speed;
	pinMode(pin1, OUTPUT);
	pinMode(pin2, OUTPUT);
	pinMode(pin3, OUTPUT);
	pinMode(pin4, OUTPUT);
	pinMode(firstenable, OUTPUT);
	pinMode(secondenable, OUTPUT);
	digitalWrite(firstenable, HIGH);
	digitalWrite(secondenable, HIGH);
}

/*
	Function used to rotate the stand 72 degrees.
*/
void Motor::rotate1() {
	step1();
	delay(time);
	step2();
	delay(time);
	step3();
	delay(time);
	step4();
}
/*
	Function used to rotate the stand 18 degrees.
*/
void Motor::step1() {
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
}
/*
	Function used to rotate the stand 18 degrees.
*/
void Motor::step2() {
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, HIGH);
	digitalWrite(pin4, LOW);
}
/*
	Function used to rotate the stand 18 degrees.
*/
void Motor::step3() {
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, HIGH);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
}
/*
	Function used to rotate the stand 18 degrees.
*/
void Motor::step4() {
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, HIGH);
}
