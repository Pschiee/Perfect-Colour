/********************************************************************************
** Form generated from reading UI file 'selectcolour.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTCOLOUR_H
#define UI_SELECTCOLOUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <my_qlabel.h>

QT_BEGIN_NAMESPACE

class Ui_selectcolour
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    my_qlabel *label_browse;
    QTextEdit *colour_browse;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *Confirm;

    void setupUi(QDialog *selectcolour)
    {
        if (selectcolour->objectName().isEmpty())
            selectcolour->setObjectName(QStringLiteral("selectcolour"));
        selectcolour->resize(734, 521);
        selectcolour->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(selectcolour);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_browse = new my_qlabel(selectcolour);
        label_browse->setObjectName(QStringLiteral("label_browse"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_browse->sizePolicy().hasHeightForWidth());
        label_browse->setSizePolicy(sizePolicy);
        label_browse->setScaledContents(true);

        horizontalLayout_2->addWidget(label_browse);

        colour_browse = new QTextEdit(selectcolour);
        colour_browse->setObjectName(QStringLiteral("colour_browse"));
        sizePolicy.setHeightForWidth(colour_browse->sizePolicy().hasHeightForWidth());
        colour_browse->setSizePolicy(sizePolicy);
        colour_browse->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        colour_browse->setReadOnly(true);
        colour_browse->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_2->addWidget(colour_browse);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton = new QPushButton(selectcolour);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 230, 255);"));

        horizontalLayout->addWidget(pushButton);

        Confirm = new QPushButton(selectcolour);
        Confirm->setObjectName(QStringLiteral("Confirm"));
        sizePolicy1.setHeightForWidth(Confirm->sizePolicy().hasHeightForWidth());
        Confirm->setSizePolicy(sizePolicy1);
        Confirm->setFont(font);
        Confirm->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"background-color: rgb(255, 230, 255);"));

        horizontalLayout->addWidget(Confirm);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(selectcolour);

        QMetaObject::connectSlotsByName(selectcolour);
    } // setupUi

    void retranslateUi(QDialog *selectcolour)
    {
        selectcolour->setWindowTitle(QApplication::translate("selectcolour", "Dialog", Q_NULLPTR));
        label_browse->setText(QApplication::translate("selectcolour", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("selectcolour", "Browse", Q_NULLPTR));
        Confirm->setText(QApplication::translate("selectcolour", "Confirm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class selectcolour: public Ui_selectcolour {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTCOLOUR_H
