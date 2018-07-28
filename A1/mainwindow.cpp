#include "mainwindow.h"
#include "ui_mainwindow.h"
 QImage image(300, 300, QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    float x1,y1,x2,y2;
            x1=ui->textEdit->toPlainText().toFloat();
            y1=ui->textEdit_2->toPlainText().toFloat();
            x2=ui->textEdit_3->toPlainText().toFloat();
            y2=ui->textEdit_4->toPlainText().toFloat();
            image=DDALINE(x1,y1,x2,y2);
            ui->label_5->setPixmap(QPixmap::fromImage(image));
}

QImage MainWindow::DDALINE(float x1,float y1,float x2,float y2){

        QRgb value;
        value=qRgb(255,255,255);


    int len;

    float dx=x2-x1;
    float dy=y2-y1;

    if(abs(dx)>abs(dy))
        len=abs(dx);
                else
                len=abs(dy);
    float xinc=dx/len;
    float yinc=dy/len;
    image.setPixel(x1,y1,value);
            float x=x1+0.5;
            float y=y1+0.5;
    image.setPixel(x,y,value);
    int i=1;
    while(i<=len)
    {
    x=x+xinc;
    y=y+yinc;
    image.setPixel(x,y,value);
    i++;
    }
    return image;
                //ui->label_5->setPixmap(QPixmap::fromImage(image));

}


void MainWindow::on_textEdit_4_destroyed()
{

}

void MainWindow::on_pushButton_2_clicked()
{

  float x1,y1,x2,y2;
          x1=ui->textEdit->toPlainText().toFloat();
          y1=ui->textEdit_2->toPlainText().toFloat();
          x2=ui->textEdit_3->toPlainText().toFloat();
          y2=ui->textEdit_4->toPlainText().toFloat();
          image=BRESENHAM(x1,y1,x2,y2);
          ui->label_5->setPixmap(QPixmap::fromImage(image));
}
QImage MainWindow::BRESENHAM(float x1,float y1,float x2,float y2){

        QRgb value;
        value=qRgb(255,255,255);
        float dx=x2-x1;
        float dy=y2-y1;
        float x,y,xend,yend;

        if(dy/dx<1)
            {
            if(x1>x2){
                x=x2;
                y=y2;
                xend=x1;
            }else
            {
                x=x1;
                y=y1;
                xend=x2;
            }
            dx=abs(x2-x1);
            dy=abs(y2-y1);
            float P0=2*dy-dx;
            float P1=2*dy;
            float P2=2*(dy-dx);

            image.setPixel(x,y,value);
            while(x<xend){
                x=x+1;
                if(P0<0)
                    P0=P0+P1;
                else{
                    P0=P0+P2;
                    y=y+1;
                }
            image.setPixel(x,y,value);
            }
            }



        else
                {
            if(y1>y2){
                x=x2;
                y=y2;
                yend=y1;
            }else
            {
                x=x1;
                y=y1;
                yend=y2;
            }
            dx=abs(x2-x1);
            dy=abs(y2-y1);
            float P0=2*dx-dy;
            float P1=2*dx;
            float P2=2*(dx-dy);

            image.setPixel(x,y,value);
            while(y<yend){
                y=y+1;
                if(P0<0)
                    P0=P0+P1;
                else{
                    P0=P0+P2;
                    x=x+1;
                }
            image.setPixel(x,y,value);
            }
                }

        return image;
}
