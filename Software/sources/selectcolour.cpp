/**
 * @file selectcolour.cpp
 * @author Callum Mason + Silviya Ivanova
 * @brief The browse window for the app
 * @date 2019-04-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "includes/selectcolour.h"
#include "ui_selectcolour.h"
#include "includes/mainwindow.h"

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
	this->setWindowState(Qt::WindowFullScreen); // Set dialog window to be full screen size
	connect(ui->label_browse, SIGNAL(Mouse_Pos()),this,SLOT(Mouse_current_pos())); // Indicates mouse position
	connect(ui->label_browse, SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed())); // Indicates mouse position when mouse is pressed
	connect(ui->label_browse, SIGNAL(Mouse_Left()),this,SLOT(Mouse_left())); // Indicates mouse position when mouse button is released
}
selectcolour::~selectcolour()
{
	delete ui;
}

void selectcolour::on_pushButton_clicked()
{
	getName(); //
	loadImage(); //
	image = image.scaledToWidth(ui->label_browse->width(),Qt::SmoothTransformation); // Scale image width to the width of the label used
	image = image.scaledToHeight(ui->label_browse->height(),Qt::SmoothTransformation); // Scale image height to the height of the label used
	ui->label_browse->setPixmap(QPixmap::fromImage(image)); // Display image in label
}

void selectcolour::on_Confirm_clicked()
{
	this->hide(); // Hide dialog window
}

void selectcolour::Mouse_current_pos()
{
	QRgb tempColorRgb = image.pixel(QPoint(ui->label_browse->x,ui->label_browse->y)); // Get pixel data from mouse position on image
	QColor tempColor(tempColorRgb); // Get colour from the pixel (above)
	QPalette b = ui ->colour_browse -> palette(); // Set display area for colour selected
	b.setColor(QPalette::Base, QColor(tempColor)); // Set selected colour to be background colour for the area
	ui->colour_browse -> setPalette(b); // Show colour in area
	emit send(tempColor); // Send colour selected
}
