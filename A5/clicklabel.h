#ifndef CLICKLABEL_H
#define CLICKLABEL_H

#include <QLabel>

class clicklabel : public QLabel
{
    Q_OBJECT
public:
    float x1,y1,x2,y2;
    bool first,second;
    explicit clicklabel(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    friend class MainWindow;

signals:
    void clicked();

public slots:

};

#endif // CLICKLABEL_H
