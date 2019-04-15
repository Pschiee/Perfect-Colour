/**
* @file chosen_colour.cpp
* @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
*  @brief The class chosen_colour is used to store and access colour.
* @date 2019-04-12
*
* @copyright Copyright (c) 2019
*
*/

#include "includes/chosen_colour.h"
#include <QColor>

chosen_colour::chosen_colour(void)
{
    QColor Colour;
}

void chosen_colour::set_colour(QColor(color)){
    colour = color;
}
QColor chosen_colour::get_colour(void) {
    return colour;
}
