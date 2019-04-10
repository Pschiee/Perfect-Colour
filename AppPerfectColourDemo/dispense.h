#ifndef DISPENSE_H
#define DISPENSE_H

#include "HX711.h"
#include "Motor.h"

class dispense
{
public:
    dispense();
    HX711 HX711;
    Motor Motor;
    double cyan = 0;
    double magenta = 0;
    double yellow = 0;
    double black = 0;
    double white = 0;
    void init(double c, double m, double y, double b,double desired);

    void dispense_colour(double colour);

private:
      int speed;

      double previous_weight = 0;
      double current_weight = 0;
};
#endif // DISPENSE_H
