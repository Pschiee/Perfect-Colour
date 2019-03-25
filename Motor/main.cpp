#include <wiringPi.h>

/*! \fn void setstep(int w1, int w2, int w3, int w4)
	\brief Moves the motor 4 steps

	\param w1 1 or 0 to determine if coil 1 is on or off
	\param w2 1 or 0 to determine if coil 2 is on or off
	\param w3 1 or 0 to determine if coil 3 is on or off
	\param w4 1 or 0 to determine if coil 4 is on or off
*/

/*! \fn void steps(int time, int steps)
	\brief Moves the motor the number of steps

	\param time Delay between each step
	\param steps Number of steps to move	
*/

void setstep(int w1, int w2, int w3, int w4) {
	digitalWrite(0, w1);
	digitalWrite(1, w2);
	digitalWrite(2, w3);
	digitalWrite(3, w4);
}

void steps(int time, int steps) {
	for (int i = 0; i < steps; i++)
	{
		setstep(1, 0, 0, 0);
		delay(time);
		setstep(0, 1, 0, 0);
		delay(time);
		setstep(0, 0, 1, 0);
		delay(time);
		setstep(0, 0, 0, 1);
		delay(time);
	}
}

int main(void)
{
	wiringPiSetup();
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);	
	
	steps(200, 10);
	
	return 0;
}
