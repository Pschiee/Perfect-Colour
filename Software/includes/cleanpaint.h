#pragma once

/**
 * @file cleanpaint.h
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @brief The cleanpaint window
 * @date 2019-04-11
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef CLEANPAINT_H
#define CLEANPAINT_H

#include <QDialog>
#include "Motor.h"

namespace Ui {
  /**
 * @brief The cleanpaint window
*/

class cleanpaint;
}
/**
* @brief The cleanpaint window
*/
class cleanpaint : public QDialog
{
    Q_OBJECT

public:
    explicit cleanpaint(QWidget *parent = nullptr);
    ~cleanpaint();

private slots:
  /**
  * @brief Closes the window
  */
    void on_pushButton_2_clicked();

    /**
  * @brief Begin cleaning
  */
    void on_pushButton_clicked();

private:
    Ui::cleanpaint *ui;
    Motor MotorClean; ///< Motor MotorClean
};

#endif // CLEANPAINT_H
