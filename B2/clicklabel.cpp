#include "clicklabel.h"
#include<QMouseEvent>

clicklabel::clicklabel(QWidget *parent) :
    QLabel(parent)
{x1=y1=x2=y2=x3=y3=0;//c=0;
    first=true; second=false;
}
void clicklabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton){
    if(first==true)
    {

        x1=ev->pos().x();
        y1=ev->pos().y();//c++;
        first=false;
        emit(clicked());
        return;
    }
    if(first==false)
    {
        x2=ev->pos().x();
        y2=ev->pos().y();//c++;
        second=true;
        first=true;
    }
    emit(clicked());

                }
    if(ev->button()==Qt::RightButton){
        x3=ev->pos().x();
        y3=ev->pos().y();

    emit(clicked1());
    }
}
