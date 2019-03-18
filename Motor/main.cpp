#include <wiringPi.h>

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
