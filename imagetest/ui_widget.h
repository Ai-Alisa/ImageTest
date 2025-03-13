/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *lable2;
    QLabel *lable1;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *gamelabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(820, 392);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(820, 392));
        Widget->setMaximumSize(QSize(820, 392));
        lable2 = new QLabel(Widget);
        lable2->setObjectName("lable2");
        lable2->setGeometry(QRect(568, 30, 241, 137));
        sizePolicy.setHeightForWidth(lable2->sizePolicy().hasHeightForWidth());
        lable2->setSizePolicy(sizePolicy);
        lable2->setMinimumSize(QSize(160, 90));
        lable2->setMaximumSize(QSize(272, 153));
        lable2->setFrameShape(QFrame::Box);
        lable1 = new QLabel(Widget);
        lable1->setObjectName("lable1");
        lable1->setGeometry(QRect(10, 35, 544, 281));
        sizePolicy.setHeightForWidth(lable1->sizePolicy().hasHeightForWidth());
        lable1->setSizePolicy(sizePolicy);
        lable1->setMinimumSize(QSize(272, 153));
        lable1->setMaximumSize(QSize(544, 306));
        lable1->setFrameShape(QFrame::Box);
        lable1->setScaledContents(true);
        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(568, 180, 241, 201));
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 330, 544, 51));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(16777215, 16777211));
        pushButton->setSizeIncrement(QSize(0, 0));
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(570, 0, 241, 22));
        gamelabel = new QLabel(Widget);
        gamelabel->setObjectName("gamelabel");
        gamelabel->setGeometry(QRect(12, 0, 541, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        lable2->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        lable1->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        pushButton->setText(QString());
        gamelabel->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
