#include <wiringPi.h>
#include <iostream>

#define ADDO 5
#define ADSK 6

using namespace std;

unsigned long ReadCount(void) {
	unsigned long Count;
	unsigned char i;
	digitalWrite(ADDO, HIGH);
	digitalWrite(ADSK,LOW);
	Count = 0;
//	cout<< "digital read before: " << digitalRead(ADDO) << "\n" << flush;

		for (i = 0;i<24;i++) {
			digitalWrite(ADSK,HIGH);
			Count = Count << 1;
			digitalWrite(ADSK,LOW);
		//	cout<< "digital read: " << digitalRead(ADDO) << "\n" << flush;
			if( digitalRead(ADDO)==1) {
				Count++;
				}
			}
		digitalWrite(ADSK,HIGH);
		Count = Count^0x800000;
		digitalWrite(ADSK,LOW);
		return Count;
	}


int main(void)
 {
	unsigned long read;
	wiringPiSetup();
	pinMode(ADDO, INPUT);
	pinMode(ADSK, OUTPUT);
	digitalWrite(ADSK,LOW);
	while(1) {
	//	cout<< "Digital Out: " << digitalRead(ADDO) << "\n" << flush;
	//	cout<<"SCK: " << digitalRead(ADSK) <<"\n" << flush;
		read = ReadCount();
		cout << "Data: " << read << "\n" << flush;
	}
}


