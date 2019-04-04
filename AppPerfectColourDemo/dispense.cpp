#include "dispense.h"
#include "Motor.h"

dispense::dispense(){}

void dispense::begin(float c, float m, float y, float b) {
    int speed = 10;
    Motor Motor1;
    Motor1.init(0,1,2,3,4,5,10); //initialise
    float cyan = 100*c/255;
    float magenta = 100*m/255;
    float yellow = 100*y/255;
    float black = 100*b/255;

    Motor1.rotate(); //squeeze white paint while sensing
    delay(2000);
    Motor1.rotate(); //squeeze cyan while sensing
    delay(2000);
    Motor1.rotate(); //squeeze yellow while sensing
    delay(2000);
    Motor1.rotate(); //squeeze magenta while sensing
    delay(2000);
    Motor1.rotate(); //squeeze black while sensing
    delay(2000);
    Motor1.rotate(); //back to start
    }

