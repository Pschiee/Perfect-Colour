/**
 * @file dc_motor.h
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @brief The class DCMotor provides the functionality to drive the pusher which will push the syringe and dispense paint
 * @date 2019-04-11
 *
 * @copyright Copyright (c) 2019
 *
 */

#include <wiringPi.h>
class DCMotor {

public:
  /**
   * @brief DCMotor object constructor
   */
  DCMotor();
  /**
     * @brief Initialises the DC motor
     */
  void init();

  /**
    * @brief Drives the DC motor forward
    */

  void forward();

  /**
    * @brief Drives the DC motor backward
    */

  void backward();

  /**
    * @brief Stops the DC Motor
    */
  void stop();
};
