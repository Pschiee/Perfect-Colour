#include "HX711.h"
#include <iostream>
#include <wiringPi.h>

using namespace std;

HX711 test;

int main(void) {
	wiringPiSetup();
	test.setup(21, 22);
	test.set_scale(562.89);
	test.set_offset(8423263);
	while(1) {
		int value =test.get_units();

		cout << "Data before: " << value << " \n" << flush;

	}

}
