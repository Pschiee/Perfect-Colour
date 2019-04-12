/**
 * @file DC Motor.h
 * @author Callum Mason
 * @briefThe class DCMotor provides the functionality to drive the pusher which will push the syringe and dispense paint
 * @date 2019-04-11
 *
 * @copyright Copyright (c) 2019
 *
 */

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
