#pragma once

#ifndef WEIGHT_H
#define WEIGHT_H

#include "HX711.h"

/**
 * @file weight.h
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @briefThe class weight returns the current weight value
 * @date 2019-04-11
 *
 * @copyright Copyright (c) 2019
 *
 */

class weight
{
public:

  /**
     * @brief Weight object constructor
     */

    weight();

    HX711 HX7111; //Setting up the Weight sensor
   
    void init();
    
    float getWeight();
    
    float get_initial(float max);

private:
      
      float current_weight=0; // Current weight. 
      float previous_weight = 0;
      double previous_average = 0; // The previous average weight. 
      double current_average = 0; // The current average weight.
      double previous_final = 0; // The previous weight of the paint holder when the last paint had finished being dispensed.
};
#endif // DISPENSE_H
