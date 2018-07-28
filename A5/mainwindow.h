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


private slots:
    void on_pushButton_clicked();
void clickedev();

private:
    Ui::MainWindow *ui;
    clicklabel *l;
};

#endif // MAINWINDOW_H
