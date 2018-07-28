#ifndef CLICKLABEL_H
#define CLICKLABEL_H

#include <QLabel>

class clicklabel : public QLabel
{
    Q_OBJECT
public:
    float x1,y1,x2,y2,x3,y3;
    bool first,second;
    explicit clicklabel(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    friend class MainWindow;

signals:
    void clicked();
    void clicked1();

public slots:

};

#endif // CLICKLABEL_H
