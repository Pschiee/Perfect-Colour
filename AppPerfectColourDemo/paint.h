#ifndef PAINT_H
#define PAINT_H

#include "chosen_colour.h"
#include <QDialog>

namespace Ui {
class paint;
}

class paint : public QDialog
{
    Q_OBJECT

public:
    explicit paint(QWidget *parent = nullptr);
    ~paint();


public slots:

    void received(QColor);

private slots:

    void on_white_stateChanged(int arg1);

    void on_cyan_stateChanged(int arg1);

    void on_magenta_stateChanged(int arg1);

    void on_yellow_stateChanged(int arg1);

    void on_black_stateChanged(int arg1);

    void on_start_clicked();

private:
    Ui::paint *ui;
    chosen_colour chosenColour;
};

#endif // PAINT_H
