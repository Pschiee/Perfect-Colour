/**
 * @file Dispense.cpp
 * @author Callum Mason + Silviya Ivanova
*  @briefThe class dispense combines all the individual elements required to dispense each colour of paint.
 * @date 2019-04-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <stdio.h>
#include <QDebug>
#include <wiringPi.h>
#include "includes/dispense.h"

using namespace std;

//Constructor
dispense::dispense() {}
/*
  Function to initiliase the scales and the motor. Also calculates the amount of each colour paint to be dispensed.
*/
  
void dispense::init(double c, double m, double y, double b, double desired) {
  speed = 10;
  wiringPiSetup();
  
  double sum = c + m + y + b;
  double total = desired / sum;
  double w1 = 0;
  double w2 = 0;
  double w3 = 0;
  double w4 = 0;

  DC.init();
  Weight.init();
  Motor1.init(0, 1, 2, 3, 4, 5, 30);
  if (c > 0) {
    cyan = total * c * (c / 100);
    w1 = total * c*(1 - (c / 100));
  }
  if (m > 0) {
    magenta = total * m * (m / 100);
    w2 = total * m*(1 - (m / 100));
  }
  if (y > 0) {
    yellow = total * y * (y / 100);
    w3 = total * y*(1 - (y / 100));
  }
  if (b > 0) {
    black = total * b * (b / 100);
    w4 = total * b*(1 - (b / 100));
  }

  white = w1 + w2 + w3 + w4;

  qDebug("white: %f g\n", white);
  qDebug("Cyan: %f g \n", cyan);
  qDebug("Magenta: %f g\n", magenta);
  qDebug("Yellow: %f g\n", yellow);
  qDebug("Black: %f g\n", black);
  
}
/*
  Function used to dispense a colour of paint.
*/
void dispense::dispense_colour(double colour) {
  float sum = 0;
  float previous_difference;
  float current_difference;
  float maximum = 0;
  int i = 0;
  Clock::time_point t0= Clock::now();	
  float initial = Weight.get_initial(maximum);
  qDebug() << "Initial weight: "<< initial << "\n" <<flush;
  sum = Weight.getWeight();
  float difference = 0;
  DC.forward();
	while (difference < colour) {
		previous_difference = difference;
		sum = Weight.getWeight();
		current_difference = sum-initial;
		if (current_difference - previous_difference < 1) {
			qDebug() << "Desired difference: " << colour << "           " << flush;
			difference = current_difference; 
			qDebug() << "Actual Difference: " << difference << "\n" << flush;
	}
		
    }
    qDebug() << "\n\n\nFinal difference: " << difference << "\n\n\n" << flush;
  Clock::time_point t1 = Clock::now();
  milliseconds ms = std::chrono::duration_cast<milliseconds>(t1-t0);
  DC.backward();
  delay(ms.count()); 
  DC.stop();
  Motor1.rotate();
  delay(100); 
}

