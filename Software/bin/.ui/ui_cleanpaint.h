/********************************************************************************
** Form generated from reading UI file 'cleanpaint.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLEANPAINT_H
#define UI_CLEANPAINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_cleanpaint
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_white;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_cyan;
    QTextEdit *textEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton_magenta;
    QTextEdit *textEdit_3;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton_yellow;
    QTextEdit *textEdit_4;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *radioButton_black;
    QTextEdit *textEdit_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *cleanpaint)
    {
        if (cleanpaint->objectName().isEmpty())
            cleanpaint->setObjectName(QStringLiteral("cleanpaint"));
        cleanpaint->resize(368, 282);
        verticalLayout_2 = new QVBoxLayout(cleanpaint);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(cleanpaint);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButton_white = new QRadioButton(cleanpaint);
        radioButton_white->setObjectName(QStringLiteral("radioButton_white"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioButton_white->sizePolicy().hasHeightForWidth());
        radioButton_white->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(20);
        radioButton_white->setFont(font1);

        horizontalLayout_2->addWidget(radioButton_white);

        textEdit = new QTextEdit(cleanpaint);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_2->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioButton_cyan = new QRadioButton(cleanpaint);
        radioButton_cyan->setObjectName(QStringLiteral("radioButton_cyan"));
        sizePolicy.setHeightForWidth(radioButton_cyan->sizePolicy().hasHeightForWidth());
        radioButton_cyan->setSizePolicy(sizePolicy);
        radioButton_cyan->setFont(font1);

        horizontalLayout_3->addWidget(radioButton_cyan);

        textEdit_2 = new QTextEdit(cleanpaint);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        sizePolicy.setHeightForWidth(textEdit_2->sizePolicy().hasHeightForWidth());
        textEdit_2->setSizePolicy(sizePolicy);
        textEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(65, 68, 255);"));
        textEdit_2->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_3->addWidget(textEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        radioButton_magenta = new QRadioButton(cleanpaint);
        radioButton_magenta->setObjectName(QStringLiteral("radioButton_magenta"));
        sizePolicy.setHeightForWidth(radioButton_magenta->sizePolicy().hasHeightForWidth());
        radioButton_magenta->setSizePolicy(sizePolicy);
        radioButton_magenta->setFont(font1);

        horizontalLayout_4->addWidget(radioButton_magenta);

        textEdit_3 = new QTextEdit(cleanpaint);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        sizePolicy.setHeightForWidth(textEdit_3->sizePolicy().hasHeightForWidth());
        textEdit_3->setSizePolicy(sizePolicy);
        textEdit_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 21, 83);"));
        textEdit_3->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_4->addWidget(textEdit_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        radioButton_yellow = new QRadioButton(cleanpaint);
        radioButton_yellow->setObjectName(QStringLiteral("radioButton_yellow"));
        sizePolicy.setHeightForWidth(radioButton_yellow->sizePolicy().hasHeightForWidth());
        radioButton_yellow->setSizePolicy(sizePolicy);
        radioButton_yellow->setFont(font1);

        horizontalLayout_5->addWidget(radioButton_yellow);

        textEdit_4 = new QTextEdit(cleanpaint);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        sizePolicy.setHeightForWidth(textEdit_4->sizePolicy().hasHeightForWidth());
        textEdit_4->setSizePolicy(sizePolicy);
        textEdit_4->setStyleSheet(QStringLiteral("background-color: rgb(236, 217, 2);"));
        textEdit_4->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_5->addWidget(textEdit_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        radioButton_black = new QRadioButton(cleanpaint);
        radioButton_black->setObjectName(QStringLiteral("radioButton_black"));
        sizePolicy.setHeightForWidth(radioButton_black->sizePolicy().hasHeightForWidth());
        radioButton_black->setSizePolicy(sizePolicy);
        radioButton_black->setFont(font1);

        horizontalLayout_6->addWidget(radioButton_black);

        textEdit_5 = new QTextEdit(cleanpaint);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        sizePolicy.setHeightForWidth(textEdit_5->sizePolicy().hasHeightForWidth());
        textEdit_5->setSizePolicy(sizePolicy);
        textEdit_5->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        textEdit_5->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_6->addWidget(textEdit_5);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(cleanpaint);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(22);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 230, 255);"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(cleanpaint);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 230, 255);"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(cleanpaint);

        QMetaObject::connectSlotsByName(cleanpaint);
    } // setupUi

    void retranslateUi(QDialog *cleanpaint)
    {
        cleanpaint->setWindowTitle(QApplication::translate("cleanpaint", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("cleanpaint", "Please Select Which Colour You Would Like to Clean or Refill", Q_NULLPTR));
        radioButton_white->setText(QApplication::translate("cleanpaint", "White", Q_NULLPTR));
        radioButton_cyan->setText(QApplication::translate("cleanpaint", "Cyan", Q_NULLPTR));
        radioButton_magenta->setText(QApplication::translate("cleanpaint", "Magenta", Q_NULLPTR));
        radioButton_yellow->setText(QApplication::translate("cleanpaint", "Yellow", Q_NULLPTR));
        radioButton_black->setText(QApplication::translate("cleanpaint", "Black", Q_NULLPTR));
        pushButton->setText(QApplication::translate("cleanpaint", "Clean", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("cleanpaint", "Finish Cleaning", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cleanpaint: public Ui_cleanpaint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLEANPAINT_H
