#ifndef CSHARP_H
#define CSHARP_H

#include <QObject>
#include <QPainter>
#include <QPoint>
#include <QWidget>
#include "Pen.h"
class cshape : public QWidget//线条
{
    //Q_OBJECT
public:
   //Pen Cpen=Pen();
    int Id;
    QColor Pcol;
    int Wid;
    Qt::PenStyle Pensty;
    QPoint S;
    QPoint E;
    QColor color;
    cshape();
    cshape(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid,Qt::PenStyle sty);
    void draw(QImage &theImage);
    cshape *next;

signals:

public slots:

};
class Curve  :public cshape//曲线
{
public:
    Curve(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);
};
class Circle :public cshape//圆
{

public:
    QPoint ZX;
    int RX;
    int RY;
    Circle();
    Circle(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);
    //Circle *next=NULL;
};
class Ring :public Circle//圆环
{
public:
    Ring(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);
private:
    int RX2;
    int RY2;
};
class Rect :public cshape//长方形
{
public:
    Rect();
    Rect(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);
    int XS;
    int XE;
    int YS;
    int YE;


};
class Diamond :public Rect//菱形
{
public:

    Diamond(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);
    int XS;
    int XE;
    int YS;
    int YE;
private:
    int XL;
    int YL;
    int XR;
    int YR;

};
class Triangle:public cshape// 三角形
{
public:
    Triangle();
    Triangle(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);
    int OneX;
    int OneY;
    int TowX;
    int TowY;
    int TriX;
    int TriY;


};
class Trapezoid :public Rect//梯形
{
public:
    Trapezoid(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);
    int XN;
    int YN;
    int XW;
    int YW;


};
class Arrows :public Triangle//箭头
{
public:
    Arrows();
    Arrows(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);
    int FouX;
    int FouY;


};
class Pentagon :public Arrows//五边形
{
public:
    Pentagon();
    Pentagon(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);
    int FivX;
    int FivY;


};
class Star :public Pentagon//五角形
{
public:
    Star(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);


};
class Hexagon :public Pentagon//六边形
{
public:
    Hexagon();
    Hexagon(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);
    int SexX;
    int SexY;


};
class FCStar :public Hexagon//四角星
{
public:
    FCStar(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);
    int SevX;
    int SevY;
    int EigX;
    int EigY;
};
class TArrows :public Hexagon//第二种箭头
{
public:
    TArrows(int Id,QPoint x,QPoint y,QColor col,QColor pcol,int wid);
    void draw(QImage &theImage);
    int SevX;
    int SevY;

};


#endif // CSHARP_H
