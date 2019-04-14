#ifndef DISPENSE_H
#define DISPENSE_H

#include "HX711.h"
#include "Motor.h"
#include "dc_motor.h"
#include "weight.h"
#include <chrono>

/**
 * @file dispense.h
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @briefThe class dispense combines all the individual elements required to dispense each colour of paint.
 * @date 2019-04-11
 *
 * @copyright Copyright (c) 2019
 *
 */

class dispense
{
public:

  /**
     * @brief Dispense object constructor
     */

    dispense();

    typedef std::chrono::high_resolution_clock Clock;
    typedef std::chrono::milliseconds milliseconds;
    Motor Motor1; // Setting up the motor to rotate paints
    DCMotor DC;
    weight Weight;
    double cyan = 0; // Amount of cyan paint to be dispensed in grams
    double magenta = 0; // Amount of magenta paint to be dispensed in grams
    double yellow = 0; // Amount of yellow paint to be dispensed in grams
    double black = 0; // Amount of black paint to be dispensed in grams
    double white = 0; // Amount of white paint to be dispensed in grams

    /**
     * @brief Initialises the weight sensor and both motors.
     *
     * @param c The CMYK cyan value for the pixel selected.
     * @param m The CMYK magenta value for the pixel selected.
     * @param y The CMYK yellow value for the pixel selected.
     * @param b The CMYK black value for the pixel selected.
     * @param desired The desired amount of paint in grams.
     */
    void init(double c, double m, double y, double b,double desired);

    /**
   * @brief Dispenses the desired paint
   */

    void dispense_colour(double colour);

private:
      int speed; // Speed of rotation
      float previous_weight = 0; // Previous weight.
      float current_weight=0; // Current weight. 
      double previous_average = 0; // The previous average weight. 
      double current_average = 0; // The current average weight.
      double previous_final = 0; // The previous weight of the paint holder when the last paint had finished being dispensed.

};
#endif // DISPENSE_H
