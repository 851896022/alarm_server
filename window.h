#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <global.h>
namespace Ui {
class Window;
}

class Window : public QDialog
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

private slots:


    void on_save_clicked();

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
