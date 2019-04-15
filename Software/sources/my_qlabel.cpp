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

void my_qlabel::mouseMoveEvent(QMouseEvent *ev)
{
    this ->x = ev->x();
    this -> y = ev->y();
    emit Mouse_Pos();
}

void my_qlabel::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}

void my_qlabel::leaveEvent(QEvent *)
{
   emit Mouse_Left();
}
