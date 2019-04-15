/**
 * @file myThread.h
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @brief The thread which weighs the paint as it is being dispensed and controls the dc motor pushing.
 * @date 2019-04-11
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef MY_THREAD_H
#define MY_THREAD_H

#include "CppThread.h"
#include "Motor.h"
#include "weight.h"
#include "dc_motor.h"

#include <QDebug>
#include <chrono>

 /**
* @brief The thread which weighs the paint as it is being dispensed and controls the dc motor pushing.
*/
class myThread : public CppThread {

  /**
    * @brief THe thread initialisation.
    *
    * @param _colour The amount of the colour to be dispensed in gramms
    * @_maximum The variable used to determine the maximum starting weight that could be expected
    */
	public:
		myThread(double _colour, double _maximum) {
			DC.init();
			Weight.init();
			Motor1.init(0, 1, 2, 3, 4, 5, 30);
			colour = _colour;
			maximum = _maximum + 1;
			
			
		}
	private:
    /**
   * @brief Run the thread.
   */
		void run();

		double maximum = 0; ///< Initial maximum value
		DCMotor DC; ///< DCMotor DC
		weight Weight; ///< weight Weight
		Motor Motor1; ///< Motor Motor1
		double colour = 0; ///< Initialising amount of colour
		typedef std::chrono::high_resolution_clock Clock; ///< Initialising clock.
    typedef std::chrono::milliseconds milliseconds; ///< Initialising milliseconds.
};
	
#endif
