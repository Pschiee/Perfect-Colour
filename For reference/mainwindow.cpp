#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "selectcolour.h"
#include <QColorDialog>
#include <QColor>
#include <QFileDialog>
#include <QFile>
#include <QImage>
#include "cleanpaint.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMainWindow::showMaximized();
    QPixmap pic(":/img/img/Perfect_Colour_Logo_02.png");
//    pic = pic.scaledToWidth(ui->label_logo->width(), Qt::SmoothTransformation);
//    pic = pic.scaledToHeight(ui->label_logo->height(), Qt::SmoothTransformation);
//    ui->label_logo->setPixmap(QPixmap::fromImage(pic));
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

void MainWindow::on_pushButton_3_clicked()
{

    QColor color = QColorDialog::getColor(Qt::white,this, "Choose colour");
    store(color);
    if (color.isValid()){
        QPalette p = ui ->colour_selected -> palette();
        p.setColor(QPalette::Base, QColor(color));
        ui -> colour_selected -> setPalette(p);
        float cyan = color.cyan();
        int magenta = color.magenta();
        int yellow = color.yellow();
        int black = color.black();

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

void MainWindow::receive(QColor colour) {
    QPalette p = ui ->colour_selected -> palette();
    p.setColor(QPalette::Base, colour);
    ui -> colour_selected -> setPalette(p);
    printf("RGB : %d %d %d \n", colour.red(), colour.green(), colour.blue());
}

void MainWindow::on_pushButton_6_clicked()
{
    cleanpaint cleanpaint;
    cleanpaint.setModal(true);
    cleanpaint.exec();
}

void MainWindow::on_actionApp_Help_triggered()
{
    QMessageBox::information(this, "Welcome to our help menu", "<p>The main window of our application shows the Perfect Colour logo and "
                                                               "the colour selected from you in the box on the top right which stays white until another has been selected.</p><p>Below"
                                                               " you can see six buttons which allow actions to select from."
                                                               "</p><h3>Open Colour Window</h3><p>Allows you to open the colour wheel from which you can"
                                                               " select a colour. Press OK and this will send you back to our main page and the colour of the box in the top right "
                                                               "will change to the one selected by you. Proceed to the paint dispensing process by "
                                                               "clicking on the Mix button.</p> <h3>Browse</h3> <p>Allows you to access your own computer directories. From there you can select your own photo and colour from it."
                                                               " This will be displayed on the mainwindow."
                                                               "</p><h3>Clear</h3><p>This button clears the colour selected in case you want to change it.</p>"
                                                               "<h3>Mix</h3><p>Pressing this button </p>"
                                                               "<h3>Clean/Refill a Syringe</h3><p> Opens another window for refilling or cleaning a syringe</p>"
                                                               "<h3>Close App</h3><p>Closes the Perfect Colour app.</p><p>For more help visit our Wiki Help Page <a "
                                                               "href='https://github.com/Pschiee/Perfect-Colour/wiki/User-Manual'>HERE.</a>&nbsp;</p>" );
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

void MainWindow::on_pushButton_2_clicked()
{
    int n = QInputDialog::getDouble(this, "Select amount", "Amount selected");
}
