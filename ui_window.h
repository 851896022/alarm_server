/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QTableWidget *tableWidget;

    void setupUi(QDialog *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(1329, 973);
        tableWidget = new QTableWidget(Window);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(100, 90, 901, 731));

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QDialog *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Window", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("Window", "\346\226\260\345\273\272\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
