#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
}

Window::~Window()
{
    delete ui;
}



void Window::on_save_clicked()
{
    g->simAudioDelay[5]=ui->kp->text().toInt();
    g->simAudioDelay[7]=ui->ki->text().toInt();
    g->simAudioDelay[9]=ui->kd->text().toInt();
    g->simAudioDelay[11]=ui->cpu->text().toInt();
}
