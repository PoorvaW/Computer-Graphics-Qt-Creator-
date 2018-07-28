#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    float MAT[10][3];
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
      QImage DDALINE(float, float, float, float);
      QImage REFX();
      QImage REFY();
      QImage XY();
      QImage ROTATE(float,float,float);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
