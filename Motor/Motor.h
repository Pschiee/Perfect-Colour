#pragma once
class Motor {

public:
	Motor();
	void init(int input1, int input2, int input3, int input4, int firstenable, int secondenable, int speed);

	void rotate1();

private:
	//gpio connections
	int pin1;
	int pin2;
	int pin3;
	int pin4;
	int enableA;
	int enableB;
	int time;

	void step1();
	void step2();
	void step3();
	void step4();
};