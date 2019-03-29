#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "selectcolour.h"
#include <QColorDialog>
#include <QColor>
#include <QFileDialog>
#include <QFile>
#include <QImage>

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
