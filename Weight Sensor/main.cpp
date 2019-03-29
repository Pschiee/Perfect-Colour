#include <wiringPi.h>
#include<stdio.h>
#include<iostream>

#define PD_SCK 5
#define DOUT 6

using namespace std;

long readData() {
	long count = 0x0;
	for (int i = 0; i < 24; i++) {
		digitalWrite(PD_SCK, HIGH);
		count = count << 1;
		digitalWrite(PD_SCK, LOW);
		int read = digitalRead(DOUT);
		if (read > 0) {
	//		cout << "Dout is: " << read << "\n" << flush;
			count++;
		}
	}
	digitalWrite(PD_SCK, HIGH);
	delay(0.1);
	digitalWrite(PD_SCK, LOW);
	return count;
}

int main(void)
{
	cout << "Code running \n"<< flush;
	wiringPiSetup();
	pinMode(PD_SCK, OUTPUT);
	pinMode(DOUT, INPUT);
	digitalWrite(PD_SCK, LOW);
while(1){
	if(DOUT == 0) {

		long data = readData();
		cout<< "Data: "<< data << "\n" << flush ;
	}
}
}
