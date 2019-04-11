#include "dispense.h"

#include "HX711.h"
#include <QDebug>
#include <wiringPi.h>
#include <iostream>
#include <cmath>

using namespace std;


dispense::dispense(){}

void dispense::init(double c, double m, double y, double b,double desired) {
    speed = 10;
    double sum = c+m+y+b;
    double total = desired/sum;
    double w1 = 0;
    double w2 = 0;
    double w3 = 0;
    double w4 = 0;
    wiringPiSetup();
    HX7111.setup(21, 22);
    HX7111.set_scale(590.77);
    HX7111.set_offset(8434280);
    Motor1.init(0,1,2,3,4,5,2);
    //NEED TO CHECK THIS IN REAL LIFE
    if (c> 0){
          cyan = total * c * (c/100);
          w1 = total * c*(1-(c/100));
    }
    if (m> 0){
          magenta = total * m * (m/100);
          w2 = total * m*(1-(m/100));
    }
    if (y> 0){
         yellow = total * y * (y/100);
         w3 = total * y*(1-(y/100));
    }
    if (b> 0){
          black = total * b * (b/100);
          w4 = total * b*(1-(b/100));
    }

    white = w1+w2+w3+w4;

    qDebug("Cyan: %f g \n",cyan);
    qDebug("Magenta: %f g\n",magenta);
    qDebug("Yellow: %f g\n",yellow);
    qDebug("Black: %f g\n",black);
    qDebug("white: %f g\n",white);
    }

void dispense::dispense_colour(double colour){
    previous_weight = HX7111.get_units();
    current_weight = HX7111.get_units();
    double sum = 0;
    int i = 0;
    
    while((current_average - previous_average) < (colour + previous_final)) {
      //SQUEEZE colour
      if ((fabs(current_weight)-fabs(previous_weight)) <10) {
       if (i<5) {
	sum = sum + current_weight;
	i++;
	}
       else {
	previous_average = current_average;
        current_average = sum;
	cout << "Averaged: " << sum/i << " \n" << flush;
	i = 0;
	sum = 0;
	}
    }
  }
   //stop squeeze
    previous_final = current_average; 
    Motor1.rotate();
    }

