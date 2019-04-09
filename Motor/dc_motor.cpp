#include <wiringPi.h>


int main(void) {
  wiringPiSetup();
  pinMode(24, OUTPUT); // Input 1 Pin 35
  pinMode(27, OUTPUT); // Input 2 Pin 36
  pinMode(25, OUTPUT); // Enable A Pin 37
  pinMode(28, OUTPUT); // Enable B Pin 38

  digitalWrite(24, HIGH);
  digitalWrite(27, LOW);
  digitalWrite(25, HIGH);
  digitalWrite(28, LOW);

}



