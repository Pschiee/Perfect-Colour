#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chosen_colour.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void store(QColor tempcolour) {
        colour = tempcolour;
    }

    QColor send() {
        return colour;
    }
    QColor selected_Colour;

public slots:
    void receive(QColor);

private slots:
	void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QColor colour;
    chosen_colour chosenColour;
//    QString file_path_;

signals:
    void sent(QColor Colour);
};

#endif // MAINWINDOW_H
