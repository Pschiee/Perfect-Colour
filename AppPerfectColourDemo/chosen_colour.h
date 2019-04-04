#ifndef CHOSEN_COLOUR_H
#define CHOSEN_COLOUR_H
#include <QColor>

class chosen_colour
{
public:
    chosen_colour();
    void set_colour(QColor Color);
    QColor get_colour(void);

private:
    QColor colour;
};

#endif // CHOSEN_COLOUR_H
