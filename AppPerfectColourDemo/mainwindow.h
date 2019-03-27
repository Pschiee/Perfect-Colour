#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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

public slots:
    void receive(QColor);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QColor colour;
//    QString file_path_;
};

#endif // MAINWINDOW_H
