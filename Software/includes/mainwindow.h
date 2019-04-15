/**
 * @file mainwindow.h
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @brief The class mainwindow provides the main window for the app.
 * @date 2019-04-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chosen_colour.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
  /**
    * @brief Construct a new MainWindow object
    *
    * @param parent
    */
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
     * @brief Function used to store the colour selected so that it can be used in other functions.
     *
     * @param tempcolour The colour to be stored
     */
    void store(QColor tempcolour) {
        colour = tempcolour;
    }

    /**
     * @brief Function to send the colour to whatever requests it.
     * 
     * @return Returns the colour that was previously stored
     */
    QColor send() {
        return colour;
    }
    QColor selected_Colour; ///< Creates new QColor object

public slots:

  /**
     * @brief Sets colour of displayed colour to received colour 
     */
    void receive(QColor);

private slots:

  /**
   * @brief Pushbutton which opens mix window when clicked
   */
    void on_pushButton_2_clicked();

    /**
   * @brief Pushbutton which opens the colour window
   */
    void on_pushButton_3_clicked();

    /**
  * @brief Pushbutton which opens browse window
  */
    void on_pushButton_4_clicked();

    /**
  * @brief Pushbutton which closes the app
  */
    void on_pushButton_5_clicked();
    
    void on_pushButton_6_clicked();

    /**
  * @brief Pushbutton which clears the selected colour
  */
    void on_pushButton_clicked();
    
     void on_actionApp_Help_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    QColor colour;
    double amount;
    chosen_colour chosenColour;

signals:

  /**
  * @brief Transmits a colour
  *
  * @param Colour A QColor object
  */
    void sent(QColor Colour, double amount);
};

#endif // MAINWINDOW_H
