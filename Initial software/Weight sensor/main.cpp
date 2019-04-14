#include "HX711.h"
#include <iostream>
#include <wiringPi.h>
#include <cmath>

using namespace std;

HX711 test;

int main(void) {
	float prev_weight;
	float current_weight;
	float sum = 0;
	int i = 0;
	wiringPiSetup();
	test.setup(21, 22);
	test.set_scale(590.77);
	test.set_offset(8434280);
	prev_weight = 0;
	/*while(1) {
		current_weight = test.get_units();
		if ((fabs(current_weight)-fabs(prev_weight)) <10)
	       {
			//cout << "Difference: " << fabs(current_weight)-fabs(prev_weight) << "\n" << flush;
 			if (i<5) {
				sum = sum + current_weight;
				i++;
			}
			else {
				cout << "Averaged: " << sum/i << " \n" << flush;
				i = 0;
				sum = 0;
			}
		prev_weight = current_weight;
     		}*/

previous_weight = HX7111.get_units();
	current_weight = HX7111.get_units();
	float difference = fabs(current_weight)-fabs(previous_weight);
	//cout << "Difference: " << difference << "\n" << flush;
	//cout << "Current Weight: " << fabs(current_weight) << "\n" << flush;
	while(1) {
	if ((fabs(current_weight)-fabs(previous_weight)) <10) {

		//cout << "IN THE LOOP..... I = " << i << "\n"<< flush;
		//cout << "Difference: " << fabs(current_weight)-fabs(prev_weight) << "\n" << flush;
		cout << "IN THE LOOP..... I = " << i << "\n"<< flush;
		if (i<5) {
			sum = sum + current_weight;
			i++; 
			}

		if (i==5) {
			cout << "Averaged: " << sum/i << " \n" << flush;
			i = 0;
			sum = 0;
			}
		previous_weight = current_weight;
		}
	}

	}


