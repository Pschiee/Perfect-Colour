#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <functions.h>

using namespace cv;
using namespace std;

std::tuple<float, float, float, float> CMYK(float R, float G, float B) {

	float var_K = 1;
	float C = 1 - (R / 255);
	float M = 1 - (G / 255);
	float Y = 1 - (B / 255);

	if (C < var_K) {
		var_K = C;
	}

	if (M < var_K) {
		var_K = M;
	}

	if (Y < var_K) {
		var_K = Y;
	}

	if (var_K == 1) {
		C = 0;
		M = 0;
		Y = 0;
	}
	
	else {
		C = (C - var_K) / (1 - var_K);
		M = (M - var_K) / (1 - var_K);
		Y = (Y - var_K) / (1 - var_K);
	}

	return std::make_tuple(C, M, Y, var_K);


}

void mouseFunc(int event, int x, int y, int flag, void* param) {
	float cyan;
	float magenta;
	float yellow;
	float black;


	Mat* rgb = (Mat*)param;
	if (event == EVENT_MOUSEMOVE)
	{
		//cout << x << " " << y << endl;
	}
	if (event == EVENT_FLAG_LBUTTON) // If left mouse button is clicked
	{
		cout << x << " " << y << "\n\n\n"; //Output x and y coordinates
		cout << "RGB VALUES \n";
		cout << (int)(*rgb).at<Vec3b>(y, x)[0] << "<-- Blue \n ";
		cout << (int)(*rgb).at<Vec3b>(y, x)[1] << "<-- Green \n ";
		cout << (int)(*rgb).at<Vec3b>(y, x)[2] << "<-- Red \n ";
		cout << "CMYK VALUES\n\n\n";
		tie(cyan, magenta, yellow, black) = CMYK((int)(*rgb).at<Vec3b>(y, x)[2], (int)(*rgb).at<Vec3b>(y, x)[1], (int)(*rgb).at<Vec3b>(y, x)[0]);
		std::cout << cyan << " <--- Cyan\n";
		std::cout << magenta << " <--- Magenta\n";
		std::cout << yellow << " <--- Yellow\n";
		std::cout << black << " <--- Black\n\n\n";
	}
}