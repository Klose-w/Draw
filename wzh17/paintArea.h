#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include "Pen.h"
#include "diagram.h"
#include "operatethearea.h"
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>

class paintArea : public QWidget
{
public:
    QImage loadImage;
    paintArea();
    int mouseMark;
    Diagram Dia;
    //设置背景及大小
    void Repeal();//撤销
    void setImageSize(int width,int height);
    void setImageColor(QColor color);
     //QColor Color;
   Pen penset=Pen();
   int Mark=0;
   void setMark(int make);
   void ImaCz(int i);

   void changImage(QImage &copyImage);
   //保存及其他操作
   bool isModified()
   {
       return modified;
   }
   bool saveImage(QString &fileName,char *fileFormat);
   bool openImage(QString &fileName);
   void doPrint();
   QImage getImage();
   QColor getBackColor();
   QSize getImageSize();
   operateTheArea operater=operateTheArea();
   void ClearImage();//清除图像
private:
    QImage image;
    QRgb backcolor;

    //涂鸦工具
    QPoint lastPoint,endPoint;//定义两个坐标对象
    //保存
    bool modified;
protected:
    void paintEvent(QPaintEvent *);//重绘事件
    //涂鸦
    void mousePressEvent(QMouseEvent *event); //按下
    void mouseMoveEvent(QMouseEvent *event);  //移动
    void mouseReleaseEvent(QMouseEvent *event); //松开
    void paint(QImage &theImage);

    void MarkDraw(QImage &theImage);
    void Input();



};

#endif // PAINTAREA_H
