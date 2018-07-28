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
            image=DDALINE1(x1,y1,x2,y2);
            ui->label_5->setPixmap(QPixmap::fromImage(image));
}

QImage MainWindow::DDALINE1(float x1,float y1,float x2,float y2){

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

QImage MainWindow::DDALINE2(float x1,float y1,float x2,float y2){

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
    if(i%6==0)
    {
    image.setPixel(x,y,value);
    }
    i++;
    }
    return image;
}





void MainWindow::on_pushButton_2_clicked()
{
    float x1,y1,x2,y2;
            x1=ui->textEdit->toPlainText().toFloat();
            y1=ui->textEdit_2->toPlainText().toFloat();
            x2=ui->textEdit_3->toPlainText().toFloat();
            y2=ui->textEdit_4->toPlainText().toFloat();
            image=DDALINE2(x1,y1,x2,y2);
            ui->label_5->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_3_clicked()
{
    float x1,y1,x2,y2;
            x1=ui->textEdit->toPlainText().toFloat();
            y1=ui->textEdit_2->toPlainText().toFloat();
            x2=ui->textEdit_3->toPlainText().toFloat();
            y2=ui->textEdit_4->toPlainText().toFloat();
            image=DDALINE3(x1,y1,x2,y2);
            ui->label_5->setPixmap(QPixmap::fromImage(image));
}

QImage MainWindow::DDALINE3(float x1,float y1,float x2,float y2){

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
    if(i%10==0){
        for(int j=0;j<5;j++)
    image.setPixel(x+j,y+j,value);
    }
    i++;
    }
    return image;
}

void MainWindow::on_pushButton_4_clicked()
{
    float x1,y1,x2,y2;
            x1=ui->textEdit->toPlainText().toFloat();
            y1=ui->textEdit_2->toPlainText().toFloat();
            x2=ui->textEdit_3->toPlainText().toFloat();
            y2=ui->textEdit_4->toPlainText().toFloat();
            image=DDALINE4(x1,y1,x2,y2);
            ui->label_5->setPixmap(QPixmap::fromImage(image));
}
QImage MainWindow::DDALINE4(float x1,float y1,float x2,float y2){

        QRgb value;
        value=qRgb(255,255,255);

    bool dd;
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
    dd=true;
    while(i<=len)
    {
    x=x+xinc;
    y=y+yinc;
    if(i%3==0 && dd){
        int j=0;
        while(j<4){
            image.setPixel(x,y,value);
            j++;
            x=x+xinc;
            y=y+yinc;
        }
        i=i+3;
        dd=false;
    }else if(i%3==0 && !dd){
        image.setPixel(x,y,value);
        i=i+1;
        dd=true;
    }else
        i=i+1;
}
    return image;
}

void MainWindow::on_pushButton_5_clicked()
{
    float x1,y1,x2,y2;
            x1=ui->textEdit->toPlainText().toFloat();
            y1=ui->textEdit_2->toPlainText().toFloat();
            x2=ui->textEdit_3->toPlainText().toFloat();
            y2=ui->textEdit_4->toPlainText().toFloat();
            image=DDALINE5(x1,y1,x2,y2);
            ui->label_5->setPixmap(QPixmap::fromImage(image));
}
QImage MainWindow::DDALINE5(float x1,float y1,float x2,float y2){
    QRgb value;
    value=qRgb(255,255,255);

bool dd;
int len;

float dx=x2-x1;
float dy=y2-y1;

if(abs(dx)>abs(dy)){
    len=abs(dx);
    dd=true;
}
            else{
            len=abs(dy);
            dd=false;
}
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
if(dd){
    image.setPixel(x,y+1,value);
    image.setPixel(x,y-1,value);
}else
{
    image.setPixel(x+1,y,value);
    image.setPixel(x-1,y,value);
}
i++;
}
return image;

}
