#include "paint.h"
#include "ui_paint.h"
#include "dispense.h"


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
    QColor colour = chosenColour.get_colour();
    QPalette p = ui ->text -> palette();
    p.setColor(QPalette::Base, colour);
    ui -> text -> setPalette(p);

    dispense.begin(colour.cyan(),colour.magenta(),colour.yellow(),colour.black());
}
