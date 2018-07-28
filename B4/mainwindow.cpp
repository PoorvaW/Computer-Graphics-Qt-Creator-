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
    //INITIALISE
    image=DDALINE(0,150,299,150);
      image=DDALINE(150,0,150,299);
           ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_2_clicked()
{
    //DRAW DDA
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

void MainWindow::on_pushButton_3_clicked()
{
    //ABOUT X
    image=REFX();
   ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_4_clicked()
{
    //ABOUT Y
    image=REFY();
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_5_clicked()
{
    //ABOUT X=Y
    image=XY();
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_6_clicked()
{
    //ROTATE
    float a,x,y;
 a=ui->textEdit_5->toPlainText().toFloat();
 x=ui->textEdit_6->toPlainText().toFloat();
 y=ui->textEdit_7->toPlainText().toFloat();
    image=ROTATE(a,x,y);
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
QImage MainWindow::REFX(){
    float REF[3][3];
    float RES[row][3];

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            REF[i][j]=0;
    REF[0][0]=1;
    REF[1][1]=-1;
    REF[2][2]=1;


    for (int i = 0; i < (row); i++)

    {

        for (int j = 0; j < 3; j++)

        {

            RES[i][j] = 0;

            for (int k = 0; k < 3; k++)

            {

                RES[i][j] += MAT[i][k] * REF[k][j];

            }

        }

    }

    for(int i=0;i<row-1;i=i+2)
        image=DDALINE(150+RES[i][0],150-RES[i][1],150+RES[i+1][0],150-RES[i+1][1]);

return image;
}
QImage MainWindow::REFY(){
    float REF[3][3];
    float RES[row][3];

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            REF[i][j]=0;
    REF[0][0]=-1;
    REF[1][1]=1;
    REF[2][2]=1;


    for (int i = 0; i < (row); i++)

    {

        for (int j = 0; j < 3; j++)

        {

            RES[i][j] = 0;

            for (int k = 0; k < 3; k++)

            {

                RES[i][j] += MAT[i][k] * REF[k][j];

            }

        }

    }

    for(int i=0;i<row-1;i=i+2)
        image=DDALINE(150+RES[i][0],150-RES[i][1],150+RES[i+1][0],150-RES[i+1][1]);
return image;
}
QImage MainWindow::XY(){
    image=DDALINE(0,299,299,0);
    float REF[3][3];
    float RES[row][3];

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            REF[i][j]=0;
    REF[0][1]=1;
    REF[1][0]=1;
    REF[2][2]=1;


    for (int i = 0; i < (row); i++)

    {

        for (int j = 0; j < 3; j++)

        {

            RES[i][j] = 0;

            for (int k = 0; k < 3; k++)

            {

                RES[i][j] += MAT[i][k] * REF[k][j];

            }

        }

    }

    for(int i=0;i<row-1;i=i+2)
        image=DDALINE(150+RES[i][0],150-RES[i][1],150+RES[i+1][0],150-RES[i+1][1]);

return image;
}

QImage MainWindow::ROTATE(float A,float x,float y){
    float RES[row][3];
    float R[3][3];

    float a=A*3.14/180;

    R[0][0]=qCos(a);
    R[0][1]=-1*qSin(a);
    R[0][2]=0;

    R[1][0]=qSin(a);
    R[1][1]=qCos(a);
    R[1][2]=0;

    R[2][0]=-1*x*qCos(a)-y*qSin(a)+x;
    R[2][1]=x*qSin(a)-y*qCos(a)+y;
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
