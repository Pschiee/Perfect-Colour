#include <wiringPi.h>
#include "Motor.h"
#include <chrono>
#include <iostream>

using namespace std;

int main() {
	wiringPiSetup();
	typedef std::chrono::high_resolution_clock Clock; ///< Initialising clock.
    typedef std::chrono::milliseconds milliseconds; ///< Initialising milliseconds.
	Motor Motor1;
	Motor1.init(0,1,2,3,4,5,30);
	Clock::time_point t0= Clock::now();	
	for (int i =0;i<5;i++) {
			Motor1.rotate();
	}
	Clock::time_point t1 = Clock::now();
    milliseconds ms = std::chrono::duration_cast<milliseconds>(t1-t0);
    cout << "Time taken: " << ms.count() << "\n"<< flush;
	
	if (ms.count() >5950 && ms.count() < 6050) {
		cout << "Test success: \n" << flush;
	}
	
	else  {
		cout << "Test failed \n" << flush;
	}
}
