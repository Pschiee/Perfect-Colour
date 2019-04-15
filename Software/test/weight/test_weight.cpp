#include "weight.h"

#include <iostream>
#include <wiringPi.h>

using namespace std;

int main() {
	wiringPiSetup();
	weight TestWeight;
	TestWeight.init();
	float sample;
	sample = TestWeight.getWeight();
	if (sample > -0.3 && sample < 0.3) {
		cout << "Weight calibration test passed!\n" << flush;
		}
		
	else {
		cout << "Calibration Weight Test failed \n" << flush; 
		}
	cout << "PLACE 19 KG WEIGHT ON \n" << flush;	
	while(1) {
	sample = TestWeight.getWeight(); 
	
	if (sample > 18 && sample < 20) {
		cout << "Weight test passed!\n" << flush;
		cout << "Sample: " << sample <<"\n" << flush;
		return 0;}
		
	else {
		cout << "Weight Test failed \n" << flush; 
		cout << "Sample: " << sample <<"\n" << flush;}
	}
}
