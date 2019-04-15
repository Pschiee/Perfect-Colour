/********************************************************************************
** Form generated from reading UI file 'paint.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINT_H
#define UI_PAINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_paint
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QCheckBox *white;
    QCheckBox *cyan;
    QCheckBox *magenta;
    QCheckBox *yellow;
    QCheckBox *black;
    QTextEdit *text;
    QVBoxLayout *verticalLayout_2;
    QPushButton *start;
    QProgressBar *progressBar;

    void setupUi(QDialog *paint)
    {
        if (paint->objectName().isEmpty())
            paint->setObjectName(QStringLiteral("paint"));
        paint->resize(400, 300);
        widget = new QWidget(paint);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(31, 22, 316, 240));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        white = new QCheckBox(widget);
        white->setObjectName(QStringLiteral("white"));

        verticalLayout->addWidget(white);

        cyan = new QCheckBox(widget);
        cyan->setObjectName(QStringLiteral("cyan"));

        verticalLayout->addWidget(cyan);

        magenta = new QCheckBox(widget);
        magenta->setObjectName(QStringLiteral("magenta"));

        verticalLayout->addWidget(magenta);

        yellow = new QCheckBox(widget);
        yellow->setObjectName(QStringLiteral("yellow"));

        verticalLayout->addWidget(yellow);

        black = new QCheckBox(widget);
        black->setObjectName(QStringLiteral("black"));

        verticalLayout->addWidget(black);


        horizontalLayout->addLayout(verticalLayout);

        text = new QTextEdit(widget);
        text->setObjectName(QStringLiteral("text"));
        text->setReadOnly(true);

        horizontalLayout->addWidget(text);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        start = new QPushButton(widget);
        start->setObjectName(QStringLiteral("start"));

        verticalLayout_2->addWidget(start);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout_2->addWidget(progressBar);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(paint);

        QMetaObject::connectSlotsByName(paint);
    } // setupUi

    void retranslateUi(QDialog *paint)
    {
        paint->setWindowTitle(QApplication::translate("paint", "Dialog", Q_NULLPTR));
        white->setText(QApplication::translate("paint", "White", Q_NULLPTR));
        cyan->setText(QApplication::translate("paint", "Cyan", Q_NULLPTR));
        magenta->setText(QApplication::translate("paint", "Magenta", Q_NULLPTR));
        yellow->setText(QApplication::translate("paint", "Yellow", Q_NULLPTR));
        black->setText(QApplication::translate("paint", "Black", Q_NULLPTR));
        text->setHtml(QApplication::translate("paint", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Press start to begin mixing</p></body></html>", Q_NULLPTR));
        start->setText(QApplication::translate("paint", "Start mixing", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class paint: public Ui_paint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINT_H
