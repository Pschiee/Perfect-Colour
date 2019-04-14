#include "cleanpaint.h"
#include "ui_cleanpaint.h"
#include "mainwindow.h"
#include <QMessageBox>


cleanpaint::cleanpaint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cleanpaint)
{
    ui->setupUi(this);
    // this->setWindowState(Qt::WindowFullScreen);
}

cleanpaint::~cleanpaint()
{
    delete ui;
}

void cleanpaint::on_pushButton_2_clicked()
{
    this->hide();
}


void cleanpaint::on_pushButton_clicked()
{
    if (ui->radioButton_white->isChecked()){
        QMessageBox::information(this,"Cleaning in progress...", "Clean white paint syringe");
        // CLEAN CODE FOR WHITE
    }
    if (ui->radioButton_cyan->isChecked()){
        QMessageBox::information(this,"Cleaning in progress...", "Clean cyan paint syringe");
        // CLEAN CODE FOR CYAN
    }
    if (ui->radioButton_magenta->isChecked()){
        QMessageBox::information(this,"Cleaning in progress...", "Clean magenta paint syringe");
        // CLEAN CODE FOR MAGENTA
    }
    if (ui->radioButton_yellow->isChecked()){
        QMessageBox::information(this,"Cleaning in progress...", "Clean yellow paint syringe");
        // CLEAN CODE FOR YELLOW
    }
    if (ui->radioButton_black->isChecked()){
        QMessageBox::information(this,"Cleaning in progress...", "Clean black paint syringe");
        // CLEAN CODE FOR BLACK
    }
}
