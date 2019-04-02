#include <wiringPi.h>
#include "Motor.h"

int main(void) {
	int speed = 10;
	Motor Motor1;

	Motor1.init(0,1,2,3,4,5,10); // Initialise the Motor

	while (1) {
		Motor1.rotate1();	//Rotate the motor to each paint position
		delay(2000);
	}
}
