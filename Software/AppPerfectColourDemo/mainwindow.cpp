/**
 * @file mainwindow.cpp
 * @author Callum Mason + Silviya Ivanova
 * @brief The Main window for the app
 * @date 2019-04-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "selectcolour.h"
#include "paint.h"
#include <QColorDialog>
#include <QColor>
#include <QFileDialog>
#include <QFile>
#include <QImage>
#include "chosen_colour.h"
#include <wiringPi.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);

    QMainWindow::showMaximized();
    QPixmap pic(":/img/img/Perfect_Colour_Logo_02.png");
    int w=ui->label_logo->width();
    int h=ui->label_logo->height();
    ui->label_logo->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_logo->setScaledContents(true);
    QPalette p = ui ->colour_selected -> palette();
    p.setColor(QPalette::Base, QColor(255,255,255));
    ui -> colour_selected -> setPalette(p);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QColor color = chosenColour.get_colour();
	  paint paint;
    connect(this,SIGNAL(sent(QColor)), &paint, SLOT(received(QColor)));
    emit sent(color);
    paint.setModal(true);
    paint.exec(); 
}

void MainWindow::on_pushButton_3_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white,this, "Choose colour");
    store(color);
    if (color.isValid()){
        QPalette p = ui ->colour_selected -> palette();
        p.setColor(QPalette::Base, QColor(color));
        ui -> colour_selected -> setPalette(p);
        chosenColour.set_colour(color);

    }

}

void MainWindow::on_pushButton_4_clicked()
{
      selectcolour selectcolour;
      connect(&selectcolour,SIGNAL(send(QColor)), this, SLOT(receive(QColor)));
      selectcolour.setModal(true);
      selectcolour.exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    QPalette w;
    ui->colour_selected->setPalette(w);
}

void MainWindow::receive(QColor color) {
    chosenColour.set_colour(color);
    QPalette p = ui ->colour_selected -> palette();
    p.setColor(QPalette::Base, color);
    ui -> colour_selected -> setPalette(p);
}
