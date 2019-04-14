#include <wiringPi.h>
#include <iostream>

using namespace std;

void step1() {
	digitalWrite(0,HIGH);
	digitalWrite(1,LOW);
	digitalWrite(2,LOW);
	digitalWrite(3,LOW);
}
void step2() {
	digitalWrite(0,LOW);
	digitalWrite(1,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(3,LOW);
}
void step3() {
	digitalWrite(0,LOW);
	digitalWrite(1,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(3,LOW);
}
void step4() {
	digitalWrite(0,LOW);
	digitalWrite(1,LOW);
	digitalWrite(2,LOW);
	digitalWrite(3,HIGH);
}

void step5() {
	digitalWrite(0,HIGH);
	digitalWrite(1,HIGH);
	digitalWrite(2,HIGH);
	digitalWrite(3,HIGH);
}
	
int main(void) {
	wiringPiSetup();
	pinMode(0,OUTPUT);
	pinMode(1,OUTPUT);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	pinMode(5,OUTPUT);
	digitalWrite(4,HIGH);
	digitalWrite(5,HIGH);

	while (1) {
		int time =15;
		step1();
		delay(time);
		step2();
		delay(time);
		step3();
		delay(time);
		step4();
		delay(time);
	}
}
