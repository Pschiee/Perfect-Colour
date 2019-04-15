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
