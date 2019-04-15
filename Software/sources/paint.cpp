/**
 * @file paint.cpp
 * @author Callum Mason + Silviya Ivanova
 * @brief The status window while paint is being dispensed
 * @date 2019-04-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "includes/paint.h"
#include "ui_paint.h"
#include "includes/myThread.h"

#include <wiringPi.h>
#include <QDebug>


paint::paint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paint)
{
    ui->setupUi(this);
    ui->text->setText("Next to dispense: White"); // Set display to show the next colour to be dispensed
}

paint::~paint()
{
    delete ui;
}

void paint::on_white_stateChanged(int arg1)
{
    if (arg1) {
       ui->text->setText("Next to dispense: Cyan"); // Set display to show the next colour to be dispensed
    }
}

void paint::on_cyan_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(20); // Display progress on progress bar
        ui->text->setText("Next to dispense:Magenta"); // Set display to show the next colour to be dispensed
    }
}

void paint::on_magenta_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(40); // Display progress on progress bar
        ui->text->setText("Next to dispense: Yellow"); // Set display to show the next colour to be dispensed
    }
}

void paint::on_yellow_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(60); // Display progress on progress bar
        ui->text->setText("Next to dispense: Black"); // Set display to show the next colour to be dispensed
    }
}

void paint::on_black_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(80); // Display progress on progress bar
        ui->text->setText("Done!"); // Set display to show that dispensing is done
    }
}

void paint::received(QColor color, double amount) {
	desired = amount; // Get paint amount desired by the user
    QColor colour = color;
    chosenColour.set_colour(colour);
    QPalette p = ui ->text -> palette();
    p.setColor(QPalette::Base, QColor(colour));
    ui -> text -> setPalette(p); 

}

void paint::on_start_clicked()
{
    QColor colour = chosenColour.get_colour(); // Get chosen colour
    QPalette p = ui ->text -> palette(); // Get area for selected colour
    p.setColor(QPalette::Base, colour); // Set colour selected for the area
    ui -> text -> setPalette(p); 
    ui->text->setText("Now dispensing: White");
    
    wiringPiSetup(); //Set up wiringPi

    c = 100 * (colour.cyan())/255; // Cyan required in percentage
    m = 100 * (colour.magenta())/255; // Magenta required in percentage
    y = 100 * (colour.yellow())/255; // Yellow required in percentage
    b = 100 * (colour.black())/255; // Black required in percentage
    double sum = c + m + y + b;
    double total = desired / sum;
    // Set white to zero
    double w1 = 0;
    double w2 = 0;
    double w3 = 0;
    double w4 = 0;

    if (c > 0) {
      cyan = total * c * (c / 100); // Weight of cyan required
      w1 = total * c*(1 - (c / 100)); // Weight of white required from cyan
    }
    if (m > 0) {
      magenta = total * m * (m / 100); // Weight of magenta required
      w2 = total * m*(1 - (m / 100)); // Weight of white required from magenta
    }
    if (y > 0) {
      yellow = total * y * (y / 100); // Weight of yellow required
      w3 = total * y*(1 - (y / 100)); // Weight of white required from yellow
    }
    if (b > 0) {
      black = total * b * (b / 100); // Weight of black required
      w4 = total * b*(1 - (b / 100)); // Weight of white required from black
    }
    white = w1 + w2 + w3 + w4;
    myThread dispense_white(white,maximum); // Create a  thread for dispensing white paint. 
    maximum += white; // Increase the allowed maximum starting weight
    myThread dispense_cyan(cyan,maximum); // Create a  thread for dispensing cyan paint. 
    maximum += cyan; // Increase the allowed maximum starting weight
    myThread dispense_magenta(magenta,maximum); // Create a  thread for dispensing magenta paint. 
    maximum += magenta; // Increase the allowed maximum starting weight
    myThread dispense_yellow(yellow,maximum); // Create a  thread for dispensing yellow paint. 
    maximum += yellow; // Increase the allowed maximum starting weight
    myThread dispense_black(black,maximum); // Create a  thread for dispensing black paint. 
    maximum += black; // Increase the allowed maximum starting weight
    ui->white->setChecked(true); // Tick the white checkbox
    dispense_white.start(); // Start the white paint dispense thread
    dispense_white.join(); // Keep the white paint dispense thread until it is finished
    ui->cyan->setChecked(true); // Tick the cyan checkbox
    dispense_cyan.start(); // Start the cyan paint dispense thread
    dispense_cyan.join(); // Keep the white paint dispense thread until it is finished
    ui->magenta->setChecked(true); // Tick the magenta checkbox
    dispense_magenta.start(); // Start the magenta paint dispense thread
    dispense_magenta.join(); // Keep the white paint dispense thread until it is finished
    ui->yellow->setChecked(true); // Tick the yellow checkbox
    dispense_yellow.start(); // Start the yellow paint dispense thread
    dispense_yellow.join(); // Keep the white paint dispense thread until it is finished
    ui->black->setChecked(true); // Tick the black checkbox
    dispense_black.start(); // Start the black paint dispense thread
    dispense_black.join(); // Keep the white paint dispense thread until it is finished
    ui->black->setChecked(true);
    ui->progressBar->setValue(100); // Set the progress bar to 100%
}
