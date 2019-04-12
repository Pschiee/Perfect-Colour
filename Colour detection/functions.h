#pragma once
#include <stdio.h>
#include <iostream>
#include <stdint.h> 
std::tuple<float, float, float, float> CMYK(float R, float G, float B);

void mouseFunc(int event, int x, int y, int flag, void* param);