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
#include "cleanpaint.h"
#include <QMessageBox>


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

void MainWindow::on_pushButton_6_clicked()
{
    cleanpaint cleanpaint;
    cleanpaint.setModal(true);
    cleanpaint.exec();
}


void MainWindow::on_actionApp_Help_triggered()
{
    QMessageBox::information(this, "Welcome to our help menu", "<h1><strong>This help menu will navigate "
                                                               "you through our app and answer all your questions!</strong></span>"
                                                               "</h1><p>The first window that opens in front of you is the main "
                                                               "window of our application. It shows the Perfect Colour logo on the "
                                                               "top left and the colour selected from you in a box on the top right. "
                                                               "This colour wil stay white until another has been picked by you.</p><h2>Below "
                                                               "the logo and the colour selected you can see six buttons which provide "
                                                               "you with a range of actions to select from</h2><h3>Open Colour Window</h3>"
                                                               "<p>The button on the top left (Open Colour Window) allows"
                                                               " you to open our pre-made colour wheel from which you can"
                                                               " select a colour of your choice. It is displayed in a box "
                                                               "in the bottom centre. Once you are happy with the colour "
                                                               "selected, you can press OK and this will send you to our "
                                                               "main page and now the colour of the box in the top right "
                                                               "will change to the one selected by you. If you are happy "
                                                               "with it then proceed to the paint dispensing process by "
                                                               "clicking on the Mix button (second button down on the "
                                                               "right hand side).</p><h3>Browse</h3> <p>The button on"
                                                               " the top right (Browse) allows you to access your own computer "
                                                               "directories. From there you can select your own photo</p><h3>Clear</h3>"
                                                               "<p>This is the button...</p><h3>Mix</h3><p>This button...</p>"
                                                               "<h3>Clean/Refill a Syringe</h3><p>Pressing this button will "
                                                               "open another window</p><h3>Close App</h3><p>Clicking on this "
                                                               "button will close our app.</p>" );
}



void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "Learn more about Perfect Colour here...", "<h1><strong>Find more about Perfect Colour here!</strong></span></h1><p>We are a "
                                                                                                         "team of three final year students at the University of Glasgow and we are extremely happy to "
                                                                                                         "present our Real Time Embedded Programming project to you! Welcome to the one-of-a-kind acrylic "
                                                                                                         "paint dispensing machine! It can dispense any colour selected by you either by using our colour "
                                                                                                         "wheel or the colour of a pixel from you own photo!</p><h2><strong>Project "
                                                                                                         "Page:</strong></h2><p>On our Github project age you would be able to find all"
                                                                                                         " information needed to build your own paint dispensing machine. Moreover, "
                                                                                                         "you will be able to meet our team, visit our Github page &nbsp;</p> <p><a "
                                                                        "href='https://github.com/Pschiee/Perfect-Colour'>Check out our project page here.</a>&nbsp;</p>");
}
