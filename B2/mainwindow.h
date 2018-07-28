#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <clicklabel.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    QRgb val1;
    void ddaline(float,float,float,float, QRgb val1);
    void seedfill(float,float,QRgb,QRgb);

private slots:
    void on_pushButton_clicked();
void clickedev();
void clickedev1();

private:
    Ui::MainWindow *ui;
    clicklabel *l;
};

#endif // MAINWINDOW_H
