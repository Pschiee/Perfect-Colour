#ifndef MY_THREAD_H
#define MY_THREAD_H

#include "CppThread.h"
#include "Motor.h"
#include "weight.h"
#include "dc_motor.h"

#include <QDebug>
#include <chrono>

class myThread : public CppThread {
	
	public:
		myThread(double _colour, double _maximum) {
			DC.init();
			Weight.init();
			Motor1.init(0, 1, 2, 3, 4, 5, 30);
			colour = _colour;
			maximum = _maximum + 1;
			
			
		}
	private:
		void run();
		double maximum = 0;
		DCMotor DC;
		weight Weight;
		Motor Motor1;
		double colour = 0;
		typedef std::chrono::high_resolution_clock Clock;
        typedef std::chrono::milliseconds milliseconds;
	};
	
#endif
