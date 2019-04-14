/**
* @file weight.cpp
* @author Callum Mason + Silviya Ivanova
*  @briefThe class weight returns the current weight value
* @date 2019-04-12
*
* @copyright Copyright (c) 2019
*
*/

#include "includes.h"
#include <stdio.h>

using namespace std;

//Constructor
weight::weight() {}

void weight::init() {

HX7111.setup(21, 22);
HX7111.set_scale(5517);
HX7111.set_offset(8451701);

}

float weight::get_initial() {
		current_weight = HX7111.get_units();
		while (fabs(current_weight) > previous_weight + 1) {
			current_weight = HX7111.get_units(); 
			cout << "Current Weight: " << current_weight << "\n" << flush; }
		previous_weight = current_weight;
		return current_weight;
}

float weight::getWeight() {
	float sum = 0;
	int i = 0;
	//previous_weight = HX7111.get_units();
	
	float difference = fabs(current_weight)-fabs(previous_weight);
	while(1) {
		current_weight = HX7111.get_units();
	if ((fabs(current_weight)-fabs(previous_weight)) <2) {
		previous_weight = current_weight;
		if (i<5) {
			sum = sum + current_weight;
			//cout << "CurrentWeight: " << current_weight << " \n" << flush;
			i++; 
			}

		if (i==5) {
			float averaged = sum/i;
			//cout << "Averaged: " << averaged << " \n" << flush;
			i = 0;
			sum = 0;
			return averaged;
			}
		previous_weight = current_weight;
		}
	}
}



