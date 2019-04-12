#ifndef SELECTCOLOUR_H
#define SELECTCOLOUR_H

#include <QDialog>
#include <QMouseEvent>
#include <QDebug>
#include <QEvent>
#include <QLabel>
#include <QResizeEvent>
#include <QFileDialog>
#include <QColor>


namespace Ui {
class selectcolour;
//class SubQLabel;
}

class selectcolour : public QDialog
{
    Q_OBJECT

public:
    explicit selectcolour(QWidget *parent = nullptr);
    ~selectcolour();

    void getName() {
        QString name = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *.jpeg)"));
        filename = name;
         }

    void loadImage() {
        QImage tempimage;
        tempimage.load(filename);
        image = tempimage.copy();
        }

protected:
    //void resizeEvent(QResizeEvent *event);

private slots:
    void on_pushButton_clicked();
    void on_Confirm_clicked();
    void Mouse_current_pos();
    void Mouse_Pressed();
    void Mouse_left();

signals:
        void send(QColor Colour);

private:
    Ui::selectcolour *ui;
    QString filename;
    QImage image;
    QColor colour;
};  

#endif // SELECTCOLOUR_H
