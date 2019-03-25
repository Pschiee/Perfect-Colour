#include <wiringPi.h>

#define PD_SCK 4
#define DOUT 5

long readData() {
	long count = 0x0;
	for (int i = 0; i < 24; i++) {
		digitalWrite(PD_SCK, HIGH);
		count = count << 1;
		digitalWrite(PD_SCK, LOW);
		if (DOUT == 1) {
			count++;
		}
	}
	digitalWrite(PD_SCK, HIGH);
	delay(0.1);
	digitalWrite(PD_SCK, LOW);
	return count;
}

int main{

	wiringPiSetup();
	pinMode(PD_SCK, OUTPUT);
	pinMode(DOUT, INPUT);

	if(DOUT == 0) {
		long data = readData();
		printf("Data: %ld")
	}
}
