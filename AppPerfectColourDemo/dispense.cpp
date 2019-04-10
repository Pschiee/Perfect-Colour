#include "dispense.h"

#include "HX711.h"
#include <QDebug>


dispense::dispense(){}

void dispense::init(double c, double m, double y, double b,double desired) {
    speed = 10;
    double sum = c+m+y+b;
    double total = desired/sum;
    double w1 = 0;
    double w2 = 0;
    double w3 = 0;
    double w4 = 0;
   // HX711.setup(21, 22);
    //HX711.set_scale(562.89);
    //HX711.set_offset(8423263);
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
    while((current_weight - previous_weight) < colour) {
      //SQUEEZE colour
      if (HX711.get_units()-current_weight <10)
        {
       current_weight = HX711.get_units();
     }
    }
   //stop squeeze
    previous_weight = current_weight;
    Motor.rotate();
    }

