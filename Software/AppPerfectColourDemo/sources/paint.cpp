/**
 * @file pain.cpp
 * @author Callum Mason + Silviya Ivanova
 * @brief The status window while paint is being dispensed
 * @date 2019-04-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "includes/paint.h"
#include "ui_paint.h"
#include "includes/dispense.h"
#include <wiringPi.h>


paint::paint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paint)
{
    ui->setupUi(this);
}

paint::~paint()
{
    delete ui;
}

void paint::on_white_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(20);
        ui->text->setText("Now dispensing: Cyan");
    }
}

void paint::on_cyan_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(40);
         ui->text->setText("Now dispensing: Magenta");
    }
}

void paint::on_magenta_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(60);
         ui->text->setText("Now dispensing: Yellow");
    }
}

void paint::on_yellow_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(80);
         ui->text->setText("Now dispensing: Black");
    }
}

void paint::on_black_stateChanged(int arg1)
{
    if (arg1) {
        ui->progressBar->setValue(100);
         ui->text->setText("Done!");
    }
}

void paint::received(QColor color) {

    QColor colour = color;
    chosenColour.set_colour(colour);

}

void paint::on_start_clicked()
{
    dispense dispense;
    ui->text->setText("Now dispensing: White");
    QColor colour = chosenColour.get_colour();
    QPalette p = ui ->text -> palette();
    p.setColor(QPalette::Base, colour);
    ui -> text -> setPalette(p);
    double desired = 500;
    double cyan = 100 * (colour.cyan())/255;
    double magenta = 100 * (colour.magenta())/255;
    double yellow = 100 * (colour.yellow())/255;
    double black = 100 * (colour.black())/255;

    dispense.init(cyan,magenta,yellow,black,desired);
    delay(100);
    dispense.dispense_colour(dispense.white); 
    ui->white->setChecked(true); 
    dispense.dispense_colour(dispense.cyan);
    ui->cyan->setChecked(true);
    dispense.dispense_colour(dispense.magenta);
    ui->magenta->setChecked(true);
    dispense.dispense_colour(dispense.yellow);
    ui->yellow->setChecked(true);
    dispense.dispense_colour(dispense.black);
    ui->black->setChecked(true); 
}	
