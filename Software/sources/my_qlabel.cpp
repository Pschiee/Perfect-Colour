/**
 * @file my_qlabel.cpp
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @brief The class my_qlabel provides the qlabel where the pixel selection and colour retrieval is undertaken.
 * @date 2019-04-14
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "includes/my_qlabel.h"

my_qlabel::my_qlabel(QWidget *parent) :
    QLabel(parent)
{

}

void my_qlabel::mouseMoveEvent(QMouseEvent *ev) // Track mouse's x and y position while moving
{
    this ->x = ev->x(); // x coordinate
    this -> y = ev->y(); // y coordinate
    emit Mouse_Pos(); // Sends a signal of mouse's x and y position while moving
}

void my_qlabel::mousePressEvent(QMouseEvent *ev) // Monitor if mouse botton is pressed
{
    emit Mouse_Pressed(); // Sends a signal of mouse's x and y position when mouse botton is pressed
}

void my_qlabel::leaveEvent(QEvent *) // Monitor if mouse button is released
{
   emit Mouse_Left(); // Sends a signal of mouse's x and y position when mouse botton is released
}
