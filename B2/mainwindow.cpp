#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "clicklabel.h"


 QImage img(650,550,QImage::Format_RGB32);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    l=new clicklabel();
    l->setMouseTracking(true);
    l->setMinimumSize(650,550);
    connect(this->l,SIGNAL(clicked()),this, SLOT(clickedev()));
     connect(this->l,SIGNAL(clicked1()),this, SLOT(clickedev1()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int v1,v2,v3;
//,val2,val3;
    v1=ui->textEdit->toPlainText().toInt();
    v2=ui->textEdit_2->toPlainText().toInt();
    v3=ui->textEdit_3->toPlainText().toInt();
    val1=qRgb(v1,v2,v3);
    l->show();

}

void MainWindow::ddaline(float x1,float y1, float x2,float y2, QRgb val1)
{

    double len;
    if (abs(x2-x1)>=abs(y2-y1))
        len=abs(x2-x1);
    else
        len=abs(y2-y1);
    double X=(x2-x1)/len;
    double Y=(y2-y1)/len;
    double x=x1+(0.5);
    double y=y1+(0.5);
    int i=1;
    while(i<=len)
    {
        img.setPixel(x,y,val1);
        x=x+X;
        y=y+Y;
        i+=1;
     }
}


void MainWindow::clickedev()
{
   // QImage image(400,300,QImage::Format_RGB32);

    l->setPixmap(QPixmap::fromImage(img));

    if(!this->l->second)
       return;

         ddaline(l->x1,l->y1,l->x2,l->y2,val1);
        l->setPixmap(QPixmap::fromImage(img));
        return;


}
void MainWindow::seedfill(float x3,float y3,QRgb val1,QRgb nval){
QRgb c=img.pixel(x3,y3);

    if(c!=val1 && c!=nval){
        img.setPixel(x3,y3,nval);
        seedfill(x3+1,y3,val1,nval);
        seedfill(x3,y3+1,val1,nval);
        seedfill(x3-1,y3,val1,nval);
        seedfill(x3,y3-1,val1,nval);
    }
}
void MainWindow::clickedev1()
{
   // QImage image(400,300,QImage::Format_RGB32);

    l->setPixmap(QPixmap::fromImage(img));


            QRgb nval;
            nval =qRgb(255,255,255);
         seedfill(l->x3,l->y3,val1,nval);
        l->setPixmap(QPixmap::fromImage(img));
        return;


}
