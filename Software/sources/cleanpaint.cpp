/**
 * @file cleanpaint.cpp
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @brief The window which is used for the clean and refill paint option.
 * @date 2019-04-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "includes/cleanpaint.h"
#include "ui_cleanpaint.h"
#include "includes/mainwindow.h"

#include <QMessageBox>
#include <wiringPi.h>


cleanpaint::cleanpaint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cleanpaint)
{
    ui->setupUi(this);
    wiringPiSetup();
    MotorClean.init(0, 1, 2, 3, 4, 5, 30);
}

cleanpaint::~cleanpaint()
{
    delete ui;
}
/*
 Function to close the window.
*/
void cleanpaint::on_pushButton_2_clicked()
{
    this->hide();
}
/**
  Function which begins the cleaning program.
*/
void cleanpaint::on_pushButton_clicked()
{
    if (ui->radioButton_white->isChecked()){
        for (int j = 0; j<2;j++) {
			MotorClean.rotate(); }
			QMessageBox::information(this,"Cleaning in progress...", "Clean white paint syringe");
			for (int j = 0; j<3;j++) {
			MotorClean.rotate(); }
    }
    if (ui->radioButton_cyan->isChecked()){
		for (int j = 0; j<3;j++) {
			MotorClean.rotate(); }
        QMessageBox::information(this,"Cleaning in progress...", "Clean cyan paint syringe");
        for (int j = 0; j<2;j++) {
			MotorClean.rotate(); }
    }
    if (ui->radioButton_magenta->isChecked()){
		for (int j = 0; j<4;j++) {
			MotorClean.rotate(); }
        QMessageBox::information(this,"Cleaning in progress...", "Clean magenta paint syringe");
        for (int j = 0; j<1;j++) {
			MotorClean.rotate(); }
    }
    if (ui->radioButton_yellow->isChecked()){
        QMessageBox::information(this,"Cleaning in progress...", "Clean yellow paint syringe");
        
    }
    if (ui->radioButton_black->isChecked()){
		for (int j = 0; j<1;j++) {
			MotorClean.rotate(); }
        QMessageBox::information(this,"Cleaning in progress...", "Clean black paint syringe");
        for (int j = 0; j<4;j++) {
			MotorClean.rotate(); }
    }
}
