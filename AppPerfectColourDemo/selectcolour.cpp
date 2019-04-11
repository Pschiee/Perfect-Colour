#include "selectcolour.h"
#include "ui_selectcolour.h"
#include "mainwindow.h"
#include "my_qlabel.h"
#include "Motor.h"
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

selectcolour::selectcolour(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::selectcolour)
{
	ui->setupUi(this);
	this->setWindowState(Qt::WindowFullScreen);

	connect(ui->label_browse, SIGNAL(Mouse_Pos()),this,SLOT(Mouse_current_pos()));
	connect(ui->label_browse, SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
	connect(ui->label_browse, SIGNAL(Mouse_Left()),this,SLOT(Mouse_left()));
/*
	getName();
	loadImage();
	image = image.scaledToWidth(ui->label_browse->width(),Qt::SmoothTransformation);
	image = image.scaledToHeight(ui->label_browse->height(),Qt::SmoothTransformation);
	ui->label_browse->setPixmap(QPixmap::fromImage(image)); */
}
selectcolour::~selectcolour()
{
	delete ui;
}

void selectcolour::on_pushButton_clicked()
{
	getName();
	loadImage();
	image = image.scaledToWidth(ui->label_browse->width(),Qt::SmoothTransformation);
	image = image.scaledToHeight(ui->label_browse->height(),Qt::SmoothTransformation);
	ui->label_browse->setPixmap(QPixmap::fromImage(image));
}

void selectcolour::on_Confirm_clicked()
{
	this->hide();
}

void selectcolour::Mouse_current_pos()
{
	QRgb tempColorRgb = image.pixel(QPoint(ui->label_browse->x,ui->label_browse->y));
	QColor tempColor(tempColorRgb);
	QPalette b = ui ->colour_browse -> palette();
	b.setColor(QPalette::Base, QColor(tempColor));
	ui->colour_browse -> setPalette(b);
	emit send(tempColor);
}

void selectcolour::Mouse_Pressed() {
}

void selectcolour::Mouse_left() {
} 
