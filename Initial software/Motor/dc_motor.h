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
