#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
        int x11,y11,x22,y22;
        int cx1,cy1,cx2,cy2;

        QImage *l=new QImage(500,500,QImage::Format_RGB32);
        QImage *l1=new QImage(500,500,QImage::Format_RGB32);

public:
        void DDALINE(int,int,int,int);

        void DDALINE1(int,int,int,int);
        void OUTCODE(int,int,int,int);
        void INTERSECT(int x1, int y1, int x2, int y2);
        int AND(int,int);
        void CLIP(int x1, int y1, int x2, int y2);
        void mousePressEvent(QMouseEvent *e);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
signals:
    void clicked();
};

#endif // MAINWINDOW_H


