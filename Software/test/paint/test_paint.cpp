/*Using CYMK: C = 150, M = 100, Y = 100, b = 30 and a total desired of 10g.
 * 
 * Expected output: */
 
 #include <stdio.h>
 #include <iostream>
 
 using namespace std;
 
 
  int main() {
	 
  double c = 100 * (150)/255;
  double m = 100 * (100)/255;
  double y = 100 * (200)/255;
  double b = 100 * (30)/255;
  int desired = 10;
  double sum = c + m + y + b;
  double total = desired / sum;
  double w1 = 0;
  double w2 = 0;
  double w3 = 0;
  double w4 = 0;
  double cyan ,magenta,yellow,black;
      if (c > 0) {
    cyan = total * c * (c / 100);
    w1 = total * c*(1 - (c / 100));
  }
  if (m > 0) {
     magenta = total * m * (m / 100);
    w2 = total * m*(1 - (m / 100));
  }
  if (y > 0) {
    yellow = total * y * (y / 100);
    w3 = total * y*(1 - (y / 100));
  }
  if (b > 0) {
     black = total * b * (b / 100);
    w4 = total * b*(1 - (b / 100));
  }

  if (cyan >1.8 && cyan < 1.9) {
	  cout << "Cyan test success! \n" << flush;
  }
  else {
	  cout << "Cyan Test Failed" << flush; }
	  
	  
	if (magenta >0.8 && magenta < 0.9) {
	  cout << "Magenta test success! \n" << flush;
  }
  else {
	  cout << "Magenta Test Failed" << flush; }
	  
	  
	  if (yellow >3.2 && yellow < 3.3) {
	  cout << "Yellow test success! \n" << flush;
  }
  else {
	  cout << "Yellow Test Failed" << flush; }
	  
	  
	  if (black >0 && black < 0.1) {
	  cout << "Black test success! \n" << flush;
  }
  else {
	  cout << "Black Test Failed" << flush; }
	  
}

