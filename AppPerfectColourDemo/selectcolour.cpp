#include "selectcolour.h"
#include "ui_selectcolour.h"
#include "mainwindow.h"
#include <QColorDialog>
#include <QColor>
#include <QFileDialog>
#include <QFile>
#include <QPoint>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QResizeEvent>
#include "my_qlabel.h"
#include "motor.h"

selectcolour::selectcolour(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectcolour)
{
    ui->setupUi(this);
    //QWidget::showMaximized();
    this->setWindowState(Qt::WindowFullScreen);
	
    //ui->label_browse->setScaledContents(true);
    connect(ui->label_browse, SIGNAL(Mouse_Pos()),this,SLOT(Mouse_current_pos()));
    connect(ui->label_browse, SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
    connect(ui->label_browse, SIGNAL(Mouse_Left()),this,SLOT(Mouse_left()));

    getName();
    loadImage();
    image = image.scaledToWidth(ui->label_browse->width(), Qt::SmoothTransformation);
    image = image.scaledToHeight(ui->label_browse->height(), Qt::SmoothTransformation);
    ui->label_browse->setPixmap(QPixmap::fromImage(image));
}
selectcolour::~selectcolour()
{
    delete ui;
}

void selectcolour::on_pushButton_clicked()
{
//    QString filter = "All Files (*.*) ;; JPG (*.jpg) ;; PNG (*.png)";
//    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "C://", filter);
//    // QFile file_name()
//    QPixmap pic(file_name);
//    int wi=ui->label_browse->width();
//    int hi=ui->label_browse->height();
//    ui->label_browse->setPixmap(pic.scaled(wi,hi,Qt::KeepAspectRatio));
    //QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *.jpeg)"));
    // maybe add what files it can open
    //if (QString::compare(filename, QString()) !=0)
   // {
          getName();
          loadImage();
           image = image.scaledToWidth(ui->label_browse->width(), Qt::SmoothTransformation);
           image = image.scaledToHeight(ui->label_browse->height(), Qt::SmoothTransformation);
           //image = image.scaled(ui->label_browse->width(),ui->label_browse->height());
           ui->label_browse->setPixmap(QPixmap::fromImage(image));


                    //printf("RGB : %d %d %d \n", tempColor.red(), tempColor.green(), tempColor.blue());
                    //float cyan_browse = tempColor.cyan();
                   // int magenta_browse = tempColor.magenta();
                    //int yellow_browse = tempColor.yellow();
                    //int black_browse = tempColor.black();

                }

void selectcolour::on_Confirm_clicked()
{
  this->hide();
}

void selectcolour::Mouse_current_pos()
{
   QRgb tempColorRgb = image.pixel(QPoint(ui->label_browse->x, ui->label_browse->y));
   QColor tempColor(tempColorRgb);
   QPalette b = ui ->colour_browse -> palette();
   b.setColor(QPalette::Base, QColor(tempColor));
   ui -> colour_browse -> setPalette(b);
   emit send(tempColor);

}

void selectcolour::Mouse_Pressed()
{
                  // QRgb tempColorRgb = image.pixel(QPoint(ui->label_browse->x, ui->label_browse->y));
                  // QColor tempColor(tempColorRgb);
                   //QPalette b = ui ->colour_browse -> palette();
                  // b.setColor(QPalette::Base, QColor(tempColor));
                   //ui -> colour_browse -> setPalette(b);

                  // printf("RGB : %d %d %d \n", tempColor.red(), tempColor.green(), tempColor.blue());
}

void selectcolour::Mouse_left()
{

}
