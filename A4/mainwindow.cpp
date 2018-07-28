#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"
int row=0;
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
                MAT[row][0]=x1;
                MAT[row][1]=y1;
                MAT[row][2]=1;
                row++;
                MAT[row][0]=x2;
                MAT[row][1]=y2;
                MAT[row][2]=1;
                row++;

                x1=150+x1;
                y1=150-y1;
                x2=150+x2;
                y2=150-y2;
                image=DDALINE(x1,y1,x2,y2);

                ui->label->setPixmap(QPixmap::fromImage(image));
}

QImage MainWindow::DDALINE(float x1, float y1,float x2,float y2){

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

void MainWindow::on_pushButton_5_clicked()
{
    image=DDALINE(0,150,299,150);
      image=DDALINE(150,0,150,299);
           ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_2_clicked()
{
    float tx,ty;
                tx=ui->textEdit_5->toPlainText().toFloat();
                ty=ui->textEdit_6->toPlainText().toFloat();
                 image=TRANSLATE(tx,ty);
                ui->label->setPixmap(QPixmap::fromImage(image));
}
QImage MainWindow::TRANSLATE(float tx,float ty){
    float RES[row-1][3];
    float T[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(i==j)
                T[i][j]=1;
                        else
                        T[i][j]=0;
        }

    T[2][0]=tx;
    T[2][1]=ty;

    for (int i = 0; i < (row); i++)

    {

        for (int j = 0; j < 3; j++)

        {

            RES[i][j] = 0;

            for (int k = 0; k < 3; k++)

            {

                RES[i][j] += MAT[i][k] * T[k][j];

            }

        }

    }
for(int i=0;i<row-1;i=i+2)
    image=DDALINE(150+RES[i][0],150-RES[i][1],150+RES[i+1][0],150-RES[i+1][1]);

    return image;
}

void MainWindow::on_pushButton_3_clicked()
{

    float sx,sy;
                sx=ui->textEdit_7->toPlainText().toFloat();
                sy=ui->textEdit_8->toPlainText().toFloat();
                 image=SCALE(sx,sy);
                ui->label->setPixmap(QPixmap::fromImage(image));
}
QImage MainWindow::SCALE(float sx,float sy){


    float RES[row-1][3];
    float S[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(i==j)
                S[i][j]=1;
                        else
                        S[i][j]=0;
        }

    S[0][0]=sx;
    S[1][1]=sy;

    for (int i = 0; i < (row); i++)

    {

        for (int j = 0; j < 3; j++)

        {

            RES[i][j] = 0;

            for (int k = 0; k < 3; k++)

            {

                RES[i][j] += MAT[i][k] * S[k][j];

            }

        }

    }
for(int i=0;i<row-1;i=i+2)
    image=DDALINE(150+RES[i][0],150-RES[i][1],150+RES[i+1][0],150-RES[i+1][1]);

    return image;
}

void MainWindow::on_pushButton_4_clicked()
{
    float A;
    A=ui->textEdit_9->toPlainText().toFloat();
     image=ROTATE(A);
    ui->label->setPixmap(QPixmap::fromImage(image));

}
QImage MainWindow::ROTATE(float A){
    float RES[row-1][3];
    float R[3][3];

    float a=A*3.14/180;

    R[0][0]=qCos(a);
    R[0][1]=-1*qSin(a);
    R[0][2]=0;

    R[1][0]=qSin(a);
    R[1][1]=qCos(a);
    R[1][2]=0;

    R[2][0]=-1*MAT[0][0]*qCos(a)-MAT[0][1]*qSin(a)+MAT[0][0];
    R[2][1]=MAT[0][0]*qSin(a)-MAT[0][1]*qCos(a)+MAT[0][1];
    R[2][2]=1;

    for (int i = 0; i < (row); i++)

    {

        for (int j = 0; j < 3; j++)

        {

            RES[i][j] = 0;

            for (int k = 0; k < 3; k++)

            {

                RES[i][j] += MAT[i][k] * R[k][j];

            }

        }

    }
for(int i=0;i<row-1;i=i+2)
    image=DDALINE(150+RES[i][0],150-RES[i][1],150+RES[i+1][0],150-RES[i+1][1]);

    return image;

}
