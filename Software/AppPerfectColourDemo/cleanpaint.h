#ifndef CLEANPAINT_H
#define CLEANPAINT_H

#include <QDialog>

namespace Ui {
class cleanpaint;
}

class cleanpaint : public QDialog
{
    Q_OBJECT

public:
    explicit cleanpaint(QWidget *parent = nullptr);
    ~cleanpaint();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::cleanpaint *ui;
};

#endif // CLEANPAINT_H
