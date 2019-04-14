#include <wiringPi.h>

int main(void) {
	wiringPiSetup();
	pinMode(24,OUTPUT);
	pinMode(27,OUTPUT);
	pinMode(25,OUTPUT);
	pinMode(28,OUTPUT);

	digitalWrite(24,HIGH);
	digitalWrite(27,LOW);
	digitalWrite(25,HIGH);
	digitalWrite(28,LOW);
	delay(5000);
	digitalWrite(24,LOW);
	digitalWrite(27,HIGH);
	delay(5000);
	digitalWrite(25,LOW);

}
