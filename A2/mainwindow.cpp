#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
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
            x1=ui->textEdit_4->toPlainText().toFloat();
            y1=ui->textEdit_5->toPlainText().toFloat();
            x2=ui->textEdit_6->toPlainText().toFloat();
            y2=ui->textEdit_7->toPlainText().toFloat();
            image=DDALINE(x1,y1,x2,y2);
            ui->label_8->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_3_clicked()
{
    float h=ui->textEdit->toPlainText().toInt();
    float k=ui->textEdit_2->toPlainText().toInt();
    float r=ui->textEdit_3->toPlainText().toInt();
 image=BCD(h,k,r);
  ui->label_8->setPixmap(QPixmap::fromImage(image));
}


QImage MainWindow::BCD(int h,int k,int r){
        QRgb value;
        value=qRgb(255,255,255);
int x=0;
int y=r;
int d=3-2*r;

    while(x<=y){
         image.setPixel(x+h,y+k,value);
         image.setPixel(-x+h,y+k,value);
         image.setPixel(x+h,-y+k,value);
         image.setPixel(-x+h,-y+k,value);

         image.setPixel(y+k,x+h,value);
         image.setPixel(y+k,-x+h,value);
         image.setPixel(-y+k,x+h,value);
         image.setPixel(-y+k,-x+h,value);

         x=x+1;
         if(d<0)
             d=d+4*x+6;
                     else
                        {
                        d=d+4*x-4*y+10;
                        y=y-1;
                        }
    }
    return image;
}



void MainWindow::on_pushButton_2_clicked()
{

    float h=ui->textEdit->toPlainText().toFloat();
    float k=ui->textEdit_2->toPlainText().toFloat();
    float r=ui->textEdit_3->toPlainText().toFloat();
 image=DCD(h,k,r);
  ui->label_8->setPixmap(QPixmap::fromImage(image));
}



QImage MainWindow::DCD(float h,float k,float r){

        QRgb value;
        value=qRgb(255,255,255);
        float x1=r;
        float y1=0;
        float Sx=x1;
        float Sy=y1;
        int i=0;
        int val;
        do{
             val=pow(2,i);
            i++;
        }while(val<r);

        float E=1/pow(2,i-1);

        do{
            float x2=x1+E*y1;
            float y2=y1-E*x2;
            image.setPixel(h+x2,k-y2,value);
            x1=x2;
            y1=y2;
        }
        while((y1-Sy)<E||(Sx-x1)>E);
        return image;
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
}
