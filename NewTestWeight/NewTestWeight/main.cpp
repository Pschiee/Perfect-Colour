#include "HX711.h"
#include <iostream>

using namespace std;

HX711 test;

int main(void) {
	test.setup(21, 22);
	while (1) {
		
		int value = test.read();
		cout << "Data: " << value << "\n" << flush;
		
	}

}