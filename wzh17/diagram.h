#ifndef DIAGRAM_H
#define DIAGRAM_H
#include "cshape.h"

struct Ima
{
    int Mark;
    int Id;
    QPoint X;
    QPoint Y;
    QColor Col;
    QColor Pcol;
    int Wid;
    Qt::PenStyle Sty;
    Ima *next;
    Ima(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid,Qt::PenStyle sty,Ima *ptr=NULL)
    {
        Mark=0;
        Id=id;
        X=x;
        Y=y;
        Col=col;
        Pcol=pcol;
        Wid=wid;
        Sty=sty;
    }

};
class Diagram: public QWidget
{
public:
    QPoint xx;
    QPoint yy;
    int mouse;
    Ima *copy;
    Ima *first;
    Ima *second;
    Diagram();
    void Output(QImage &theImage);
    void Input(int id,QPoint x,QPoint y,QColor col,QColor pcol,int wid,Qt::PenStyle sty);
    void Transposition();
    void Repeal();//撤销
    void Choice(QPoint cp);//选择
    void ChoiceShow(QImage &theImage);//显示所需选择图形的边框
    void ImaMove(QPoint cp);//移动
    void Imachange(QPoint cp);//图形的拉升变化
    void mouseChange(QPoint cp);//鼠标变
    void Enlarge();//放大
    void Shrink();//缩小
    void changColor(QColor col);//改变颜色
    void DeleteIma();//删除指定图形
    void CopyIma();//复制
    void PasteIma();//粘贴
    void CutIma();//剪切
    void Overhead();//顶置
    void NoChoice();//不可选择
    void SeRepeal();//
    void ImageClear();//清除图像
};

#endif // DIAGRAM_H
