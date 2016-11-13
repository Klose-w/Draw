#include "cshape.h"
#include "paintarea.h"

//线条
cshape::cshape()
{

}

cshape::cshape(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid,Qt::PenStyle sty)
{
    Id=id;
    S=x;
    E=y;
    color=col;
    Pcol=pcol;
    Wid=wid;
    Pensty=sty;
    next=NULL;

}

void cshape::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    Cpen.setStyle(Pensty);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    pp.drawLine(S,E);
    update();

}
//曲线
Curve::Curve(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    color=col;
    Pcol=pcol;
    Wid=wid;
}

void Curve::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    //pp.setBrush(QBrush(color,Qt::SolidPattern));


    QPoint c1(S.x(),E.y());
    QPoint c2((S+E).x()/2,S.y());
    //pp.drawRect(c1.x()-2,c1.y()-2,2,2);
    QPainterPath path(c1);
    path.cubicTo(c2,c2,E);


    pp.drawPath(path);
}
//圆环
Ring::Ring(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    ZX=(S+E)/2;
    RX=abs(S.x()-E.x())/2;
    RY=abs(S.y()-E.y())/2;
    color=col;
    Pcol=pcol;
    Wid=wid;
    RX2=abs(S.x()-E.x())/5*2;
    RY2=abs(S.y()-E.y())/5*2;
}
void Ring::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    pp.drawEllipse(ZX,RX,RY);
    pp.setBrush(QBrush(Pcol,Qt::SolidPattern));
    pp.drawEllipse(ZX,RX2,RY2);
    update();

}
//圆
Circle::Circle(){}
Circle::Circle(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    ZX=(S+E)/2;
    RX=abs(S.x()-E.x())/2;
    RY=abs(S.y()-E.y())/2;
    color=col;
    Pcol=pcol;
    Wid=wid;
}

void Circle::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    pp.drawEllipse(ZX,RX,RY);
    update();

}
//长方形
Rect::Rect(){}
Rect::Rect(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    XS=S.x();
    YS=S.y();
    XE=E.x()-S.x();
    YE=E.y()-S.y();
    color=col;
    Pcol=pcol;
    Wid=wid;
}

void Rect::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    pp.drawRect(XS,YS,XE,YE);
    update();

}
//菱形

Diamond::Diamond(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    XS=(S.x()+E.x())/2;
    YS=S.y();
    XL=S.x();
    YL=(S.y()+E.y())/2;
    XE=(S.x()+E.x())/2;
    YE=E.y();
    XR=E.x();
    YR=YL=(S.y()+E.y())/2;
    color=col;
    Pcol=pcol;
    Wid=wid;
}

void Diamond::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    QPolygonF polygon;
    polygon << QPointF(XS,YS) << QPointF(XL,YL)
            <<  QPointF(XE,YE)<< QPointF(XR,YR);
    pp.drawPolygon(polygon, Qt::WindingFill);

    update();

}

//三角
Triangle::Triangle(){}
Triangle::Triangle(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    OneX=S.x();
    OneY=E.y();
    TowX=E.x();
    TowY=E.y();
    TriX=(S.x()+E.x())/2;
    TriY=S.y();

    color=col;
    Pcol=pcol;
    Wid=wid;
}

void Triangle::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    QPolygonF polygon;
    polygon << QPointF(OneX,OneY) << QPointF(TowX,TowY)
            <<  QPointF(TriX, TriY);
    pp.drawPolygon(polygon, Qt::WindingFill);

    update();

}
//梯形
Trapezoid::Trapezoid(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    XS=S.x()+(E.x()-S.x())/4;
    YS=S.y();
    XE=E.x();
    YE=E.y();
    XN=E.x()-(E.x()-S.x())/4;
    YN=S.y();\
    XW=S.x();
    YW=E.y();
    color=col;
    Pcol=pcol;
    Wid=wid;
}
void Trapezoid::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    QPolygonF polygon;
    polygon << QPointF(XS,YS) << QPointF(XN,YN)<< QPointF(XE,YE)
            <<  QPointF(XW, YW);
    pp.drawPolygon(polygon, Qt::WindingFill);

    update();

}
//箭头
Arrows::Arrows(){}
Arrows::Arrows(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    OneX=S.x()+(E.x()-S.x())/2;
    OneY=S.y();
    TowX=S.x();
    TowY=E.y();
    TriX=S.x()+(E.x()-S.x())/2;
    TriY=E.y()-(E.y()-S.y())/3;
    FouX=E.x();
    FouY=E.y();
    color=col;
    Pcol=pcol;
    Wid=wid;
}

void Arrows::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    QPolygonF polygon;
    polygon << QPointF(OneX,OneY) << QPointF(TowX,TowY)
            <<  QPointF(TriX, TriY)<<QPointF(FouX,FouY);
    pp.drawPolygon(polygon, Qt::WindingFill);

    update();

}
//五边形
Pentagon::Pentagon(){}
Pentagon::Pentagon(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    OneX=S.x()+(E.x()-S.x())/2;
    OneY=S.y();
    TowX=S.x();
    TowY=S.y()+(E.y()-S.y())/3;
    TriX=S.x()+(E.x()-S.x())/5;
    TriY=E.y();
    FouX=E.x()-(E.x()-S.x())/5;
    FouY=E.y();
    FivX=E.x();
    FivY=S.y()+(E.y()-S.y())/3;
    color=col;
    Pcol=pcol;
    Wid=wid;
}

void Pentagon::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    QPolygonF polygon;
    polygon << QPointF(OneX,OneY) << QPointF(TowX,TowY)
            <<  QPointF(TriX, TriY)<<QPointF(FouX,FouY)<< QPointF(FivX,FivY);
    pp.drawPolygon(polygon, Qt::WindingFill);

    update();

}
//五角星
Star::Star(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    OneX=S.x()+(E.x()-S.x())/2;
    OneY=S.y();
    TowX=S.x();
    TowY=S.y()+(E.y()-S.y())/3;
    TriX=S.x()+(E.x()-S.x())/5;
    TriY=E.y();
    FouX=E.x()-(E.x()-S.x())/5;
    FouY=E.y();
    FivX=E.x();
    FivY=S.y()+(E.y()-S.y())/3;
    color=col;
    Pcol=pcol;
    Wid=wid;
}

void Star::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    QPolygonF polygon;
    polygon << QPointF(OneX,OneY) << QPointF(TriX,TriY)
            <<  QPointF(FivX, FivY)<<QPointF(TowX,TowY)<< QPointF(FouX,FouY);
    pp.drawPolygon(polygon, Qt::WindingFill);

    update();

}
//六边形
Hexagon::Hexagon(){}
Hexagon::Hexagon(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    OneX=S.x()+(E.x()-S.x())/4;
    OneY=S.y();
    TowX=S.x();
    TowY=S.y()+(E.y()-S.y())/2;
    TriX=S.x()+(E.x()-S.x())/4;
    TriY=E.y();
    FouX=E.x()-(E.x()-S.x())/4;
    FouY=E.y();
    FivX=E.x();
    FivY=S.y()+(E.y()-S.y())/2;
    SexX=E.x()-(E.x()-S.x())/4;
    SexY=S.y();
    color=col;
    Pcol=pcol;
    Wid=wid;
}

void Hexagon::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    QPolygonF polygon;
    polygon << QPointF(OneX,OneY) << QPointF(TowX,TowY)
            <<  QPointF(TriX, TriY)<<QPointF(FouX,FouY)
             << QPointF(FivX,FivY)<<QPointF(SexX,SexY);
    pp.drawPolygon(polygon, Qt::WindingFill);

    update();

}
//四角星
FCStar::FCStar(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    OneX=(S.x()+E.x())/2;
    OneY=S.y();
    TowX=S.x()+(E.x()-S.x())/5*2;
    TowY=S.y()+(E.y()-S.y())/5*2;
    TriX=S.x();
    TriY=S.y()+(E.y()-S.y())/2;
    FouX=S.x()+(E.x()-S.x())/5*2;
    FouY=S.y()+(E.y()-S.y())/5*3;
    FivX=(S.x()+E.x())/2;
    FivY=E.y();
    SexX=S.x()+(E.x()-S.x())/5*3;
    SexY=S.y()+(E.y()-S.y())/5*3;
    SevX=E.x();
    SevY=(S.y()+E.y())/2;
    EigX=S.x()+(E.x()-S.x())/5*3;
    EigY=S.y()+(E.y()-S.y())/5*2;
    color=col;
    Pcol=pcol;
    Wid=wid;
}
void FCStar::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    QPolygonF polygon;
    polygon << QPointF(OneX,OneY) << QPointF(TowX,TowY)
            <<  QPointF(TriX, TriY)<<QPointF(FouX,FouY)
             << QPointF(FivX,FivY)<<QPointF(SexX,SexY)
                << QPointF(SevX,SevY)<<QPointF(EigX,EigY);
    pp.drawPolygon(polygon, Qt::WindingFill);

    update();

}
//第二种箭头
TArrows::TArrows(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid)
{
    Id=id;
    S=x;
    E=y;
    OneX=(S.x()+E.x())/2;
    OneY=S.y();
    TowX=S.x();
    TowY=S.y()+(E.y()-S.y())/3;
    TriX=S.x()+(E.x()-S.x())/5;
    TriY=S.y()+(E.y()-S.y())/3;
    FouX=S.x()+(E.x()-S.x())/5;
    FouY=E.y();
    FivX=S.x()+(E.x()-S.x())/5*4;
    FivY=E.y();
    SexX=S.x()+(E.x()-S.x())/5*4;
    SexY=S.y()+(E.y()-S.y())/3;
    SevX=E.x();
    SevY=S.y()+(E.y()-S.y())/3;
    color=col;
    Pcol=pcol;
    Wid=wid;
}
void TArrows::draw(QImage &theImage)
{
    QPen Cpen=QPen();
    QPainter pp(&theImage);
    Cpen.setColor(Pcol);
    Cpen.setWidth(Wid);
    pp.setPen(Cpen);
    pp.setBrush(QBrush(color,Qt::SolidPattern));
    QPolygonF polygon;
    polygon << QPointF(OneX,OneY) << QPointF(TowX,TowY)
            <<  QPointF(TriX, TriY)<<QPointF(FouX,FouY)
             << QPointF(FivX,FivY)<<QPointF(SexX,SexY)
                << QPointF(SevX,SevY);
    pp.drawPolygon(polygon, Qt::WindingFill);

    update();

}
