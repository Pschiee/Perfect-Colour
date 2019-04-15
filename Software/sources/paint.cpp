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
    ui->text->setText("Next to dispense: White");
}

paint::~paint()
{
    delete ui;
}

void paint::on_white_stateChanged(int arg1)
{
    if (arg1) {
       ui->text->setText("Next to dispense: Cyan");
    }
}

void paint::on_cyan_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(20);
        ui->text->setText("Next to dispense:Magenta");
    }
}

void paint::on_magenta_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(40);
        ui->text->setText("Next to dispense: Yellow");
    }
}

void paint::on_yellow_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(60);
        ui->text->setText("Next to dispense: Black");
    }
}

void paint::on_black_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(80);
        ui->text->setText("Done!");
    }
}

void paint::received(QColor color, double amount) {
	desired = amount;
    QColor colour = color;
    chosenColour.set_colour(colour);
    QPalette p = ui ->text -> palette();
    p.setColor(QPalette::Base, QColor(colour));
    ui -> text -> setPalette(p); 

}

void paint::on_start_clicked()
{
    QColor colour = chosenColour.get_colour();
    QPalette p = ui ->text -> palette();
    p.setColor(QPalette::Base, colour);
    ui -> text -> setPalette(p); 
    ui->text->setText("Now dispensing: White");
    
  wiringPiSetup();

     c = 100 * (colour.cyan())/255;
     m = 100 * (colour.magenta())/255;
     y = 100 * (colour.yellow())/255;
     b = 100 * (colour.black())/255;
  double sum = c + m + y + b;
  double total = desired / sum;
  double w1 = 0;
  double w2 = 0;
  double w3 = 0;
  double w4 = 0;
      if (c > 0) {
     cyan = total * c * (c / 100);
    w1 = total * c*(1 - (c / 100));
  }
  if (m > 0) {
    magenta = total * m * (m / 100);
    w2 = total * m*(1 - (m / 100));
  }
  if (y > 0) {
   yellow = total * y * (y / 100);
    w3 = total * y*(1 - (y / 100));
  }
  if (b > 0) {
    black = total * b * (b / 100);
    w4 = total * b*(1 - (b / 100));
  }
  white = w1 + w2 + w3 + w4;
  myThread dispense_white(white,maximum);
  maximum += white;
  myThread dispense_cyan(cyan,maximum);
  maximum += cyan;
  myThread dispense_magenta(magenta,maximum);
  maximum += magenta;
  myThread dispense_yellow(yellow,maximum);
  maximum += yellow;
  myThread dispense_black(black,maximum);
  maximum += black;
  ui->white->setChecked(true); 
  dispense_white.start();
  dispense_white.join();
  ui->cyan->setChecked(true);
  dispense_cyan.start();
  dispense_cyan.join();
  ui->magenta->setChecked(true);
  dispense_magenta.start();
  dispense_magenta.join();
  ui->yellow->setChecked(true);
  dispense_yellow.start();
  dispense_yellow.join();
  ui->black->setChecked(true);
  dispense_black.start();
  dispense_black.join();
  ui->black->setChecked(true);
  ui->progressBar->setValue(100);
}
