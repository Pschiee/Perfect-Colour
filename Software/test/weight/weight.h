/**
 * @file weight.h
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @brief The class weight returns the current weight value
 * @date 2019-04-11
 *
 * @copyright Copyright (c) 2019
 *
 */


#pragma once

#ifndef WEIGHT_H
#define WEIGHT_H

#include "HX711.h"

 /**
 * @brief The class weight returns the current weight value
*/
class weight
{
public:

  /**
     * @brief Weight object constructor
     */

    weight();

    HX711 HX7111; ///< Setting up the Weight sensor
   
    /**
   * @brief The initialising function
   */
    void init();
    
    /**
   * @brief Filters out incorrect values and then takes a running average of 5 values.
   * @return Returns the average weight in gramms.
   */
    float getWeight(); 
    
    /**
  * @brief Filters out incorrect values and then takes a running average of 5 values.
  * @return Returns the average weight in gramms.
  */
    float get_initial(float max);

private:
      
      float current_weight=0; ///< Current weight. 
      float previous_weight = 0; ///< Previous weight. 
};
#endif // DISPENSE_H
