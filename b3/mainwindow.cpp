#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <iostream>
bool flag=true;
int xmin=100,ymin=100,xmax=400,ymax=400;
int code[4];
int code1[4];

 //QImage image(300, 300, QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    DDALINE(100,100,400,100);
    DDALINE(100,100,100,400);
    DDALINE(100,400,400,400);
    DDALINE(400,100,400,400);

    QImage g= l->convertToFormat(QImage::Format_RGBA8888);
    ui->label->setPixmap(QPixmap::fromImage(g));
    DDALINE1(100,100,400,100);
    DDALINE1(100,100,100,400);
    DDALINE1(100,400,400,400);
    DDALINE1(400,100,400,400);

    QImage h= l1->convertToFormat(QImage::Format_RGBA8888);
    ui->label_2->setPixmap(QPixmap::fromImage(h));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(flag){
        x11=e->pos().x();
        y11=e->pos().y();
        flag=false;
    }else
    {
        x22=e->pos().x();
        y22=e->pos().y();
        DDALINE(x11,y11,x22,y22);

        QImage g= l->convertToFormat(QImage::Format_RGBA8888);
      ui->label->setPixmap(QPixmap::fromImage(g));
        flag=true;

        OUTCODE(x11,y11,x22,y22);
        CLIP(x11,y11,x22,y22);
    }
}

void MainWindow::CLIP(int x1,int y1,int x2,int y2){
int i=0;
    while(code[i]==0&&code1[i]==0&&i!=4)
    {
        i++;
    }
    if(i==4)
    {
        DDALINE1(x1,y1,x2,y2);
        QImage h= l1->convertToFormat(QImage::Format_RGBA8888);
        ui->label_3->setText(QString("                                                    LINE COMPLETELY VISIBLE"));

      ui->label_2->setPixmap(QPixmap::fromImage(h));
      return;
    }else{
            int res[4];
            for(int k=0;k<4;i++)
                res[k]=AND(code[k],code1[k]);
            int j=0;
            while(res[j]==0&&i!=4)
            {
                j++;
            }
            if(j!=4)
            {
                //completely invisible
                ui->label_3->setText(QString("Line Completely Invisible"));
                        return;
            }/*else
            {
                INTERSECT(x1,y1,x2,y2);
                OUTCODE(cx1,cy1,cx2,cy2);
                CLIP(cx1,cy1,cx2,cy2);

            }*/
    }
}


void MainWindow::OUTCODE(int x1, int y1, int x2, int y2)
{
     if(x1<xmin)
        code[3]=1;
            else
               code[3]=0;
     if(x1>xmax)
         code[2]=1;
            else
               code[2]=0;
     if(y1>ymax)
               code[1]=1;
             else
               code[1]=0;
     if(y1<ymin)
               code[0]=1;
              else
               code[0]=0;


     if(x2<xmin)
        code1[3]=1;
            else
               code1[3]=0;
     if(x2>xmax)
         code1[2]=1;
            else
               code1[2]=0;
     if(y2>ymax)
         code1[1]=1;
             else
               code1[1]=0;
     if(y2<ymin)
         code1[0]=1;
              else
               code1[0]=0;

}

void MainWindow::DDALINE(int x1, int y1, int x2, int y2)  //DDA Line Algorithm

{
    QRgb value=qRgb(100,100,100);

            int i,dx,dy,steps;
            float x,y;
            float xinc,yinc;

            dx=(x2-x1);
            dy=(y2-y1);
            if(abs(dx)>=abs(dy))
                {
                    steps=abs(dx);
                }
                else
                    {
                        steps=abs(dy);
                    }
             xinc=(float)dx/steps;
             yinc=(float)dy/steps;
             x=x1;
             y=y1;
             std::cout<<x<<y<<x2<<y2;
            l->setPixel(x,y,value);
             for(i=1;i<steps;i++)
                {
                    x=x+xinc;
                    y=y+yinc;
                   // x1=(int)((float)x+t);
                    //y1=(int)((float)y+t);
                l->setPixel(x,y,value);
             }

        }


void MainWindow::DDALINE1(int x1, int y1, int x2, int y2)  //DDA Line Algorithm

{
    QRgb value=qRgb(100,100,100);

            int i,dx,dy,steps;
            float x,y;
            float xinc,yinc;

            dx=(x2-x1);
            dy=(y2-y1);
            if(abs(dx)>=abs(dy))
                {
                    steps=abs(dx);
                }
                else
                    {
                        steps=abs(dy);
                    }
             xinc=(float)dx/steps;
             yinc=(float)dy/steps;
             x=x1;
             y=y1;
             std::cout<<x<<y<<x2<<y2;
            l1->setPixel(x,y,value);
             for(i=1;i<steps;i++)
                {
                    x=x+xinc;
                    y=y+yinc;
                   // x1=(int)((float)x+t);
                    //y1=(int)((float)y+t);
                l1->setPixel(x,y,value);
             }

        }


int MainWindow::AND(int one,int two)
{
    if(one==0 || two==0)
        return 0;
    else
        return 1;
}
void MainWindow::INTERSECT(int x1, int y1, int x2, int y2){

}
