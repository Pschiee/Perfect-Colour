/**
 * @file myThread.cpp
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @brief The thread which weighs the paint as it is being dispensed and controls the dc motor pushing.
 * @date 2019-04-11
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "includes/myThread.h"

#include <stdio.h>
#include <thread>
#include <QDebug>
#include <wiringPi.h>
#include <chrono>

void myThread::run() {
  float sum = 0;
  float previous_difference;
  float current_difference;
  Clock::time_point t0= Clock::now();	
  float initial = Weight.get_initial(maximum);
  sum = Weight.getWeight();
  float difference = 0;
  DC.forward();
	while (difference < colour) {
		previous_difference = difference;
		sum = Weight.getWeight();
		current_difference = sum-initial;
		if (current_difference - previous_difference < 1) {
			difference = current_difference; 
	}
		
    }
  Clock::time_point t1 = Clock::now();
  milliseconds ms = std::chrono::duration_cast<milliseconds>(t1-t0);
  DC.backward();
  delay(ms.count()); 
  DC.stop();
  Motor1.rotate();
}
