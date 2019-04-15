/**
 * @file my_qlabel.h
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @brief The class my_qlabel provides the qlabel where the pixel selection and colour retrieval is undertaken.
 * @date 2019-04-14
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef MY_QLABEL_H
#define MY_QLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QEvent>

 /**
  * @brief The custom QLabel classes.
 */
class my_qlabel : public QLabel
{
    Q_OBJECT
public:
  /**
    * @brief Construct a new my_qlabel object.
    *
    * @param parent
    */
    explicit my_qlabel(QWidget *parent=0);

    /**
    * @brief Occurs when the mouse is moved.
    */
    void mouseMoveEvent(QMouseEvent *ev);

    /**
   * @brief Occurs when the mouse is pressed.
   */
    void mousePressEvent(QMouseEvent  *ev);

    /**
  * @brief Occurs when the mouse leaves the label.
  */
    void leaveEvent(QEvent *);

    int x; ///< x coordinate
    int y; ///< y coordinate

signals:

  /**
 * @brief The mouse is pressed.
 */
   void Mouse_Pressed();

   /**
 * @brief The mouse position.
 */
   void Mouse_Pos();

   /**
* @brief The mouse left button has been clicked.
*/
   void Mouse_Left();

};

#endif // MY_QLABEL_H
