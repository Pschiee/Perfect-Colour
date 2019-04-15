/**
* @file weight.cpp
* @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
*  @briefThe class weight returns the current weight value
* @date 2019-04-12
*
* @copyright Copyright (c) 2019
*
*/
#include "includes/weight.h"

#include <cmath>
#include <stdio.h>
#include <QDebug>

using namespace std;

//Constructor
weight::weight() {}

void weight::init() {

HX7111.setup(21, 22);
HX7111.set_scale(554.736);
HX7111.set_offset(8452100);

}

float weight::get_initial(float maximum) {
		current_weight = HX7111.get_units();
		while (fabs(current_weight) > maximum) {
			current_weight = HX7111.get_units(); 
		 }
		previous_weight = current_weight;
		return current_weight;
}

float weight::getWeight() {
	float sum = 0;
	int i = 0;
	previous_weight = HX7111.get_units();
	
	float difference = fabs(current_weight)-fabs(previous_weight);
	while(1) {
		current_weight = HX7111.get_units();
	if ((fabs(current_weight)-fabs(previous_weight)) <2) {
		previous_weight = current_weight;
		if (i<5) {
			sum = sum + current_weight;
			i++; 
			}

		if (i==5) {
			float averaged = sum/i;
			i = 0;
			sum = 0;
			return averaged;
			}
		previous_weight = current_weight;
		}
	}
}



