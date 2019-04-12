#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <functions.h>


using namespace cv;
using namespace std;

int main() {

	Mat colour = imread("leire.png", CV_LOAD_IMAGE_COLOR); //Create Mat object with image

	namedWindow("Leire", CV_WINDOW_FREERATIO); // Creates the window called Leire 
	imshow("Leire", colour); //Show the image on the window

	Point p;
	
	setMouseCallback("Leire", mouseFunc, &colour);

	waitKey(0);

}