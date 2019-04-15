/**
 * @file chosen_colour.h
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @brief The class chosen_colour is used to store and access colour.
 * @date 2019-04-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef CHOSEN_COLOUR_H
#define CHOSEN_COLOUR_H
#include <QColor>

class chosen_colour
{
public:
  /**
     * @brief chosen_colour object constructor
     */
    chosen_colour();

    /**
     * @brief Sets the colour and stores it
     * @param Color The colour to be stored.
     */
    void set_colour(QColor Color);

    /**
   * @brief Sends the colour and stores it
   * @return Returns the colour to be stored.
   */
    QColor get_colour(void);

private:
    QColor colour; ///< QColor colour
};

#endif // CHOSEN_COLOUR_H
