#include "paintarea.h"
#include<QPainter>
#include"cshape.h"
#include "Pen.h"
#include "diagram.h"
paintArea::paintArea()
{
    mouseMark=0;
    image=QImage(400,400,QImage::Format_RGB32);//画布初始化

    backcolor=qRgb(255,255,255);//画布初始背景色
    image.fill(backcolor);

   loadImage=image;
    //image=loadImage;
}
void paintArea::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
   QPointF center(image.width()/2.0,image.height()/2.0);
    painter.scale(operater.scale,operater.scale);
    if(operater.angle)
    {
        painter.translate(center);
        painter.rotate(operater.angle);
        painter.translate(-center);
    }
    if(operater.numOfStretch)
    {
        QImage copyImage=image;
        QPainter pp(&copyImage);
//painter.shear(operater.numOfStretch,operater.numOfStretch);

        pp.shear(operater.numOfStretch,operater.numOfStretch);

        pp.drawImage(0,0,image);
        image=copyImage;
        operater.numOfStretch=0;
    }


 painter.drawImage(0,0,image);



//    QPainter painter(this);
//    QPointF center(image.width()/2.0,image.height()/2.0);
//        painter.scale(operater.scale,operater.scale);
//        if(operater.angle)
//        {
//           // QImage copyImage=image;
//           // QPainter pp(&copyImage);
//     //QPointF center(image.width()/2.0,image.height()/2.0);

//           // QPointF center(copyImage.width()/2.0,copyImage.height()/2.0);
//            painter.translate(center);
//            painter.rotate(operater.angle);
//            painter.translate(-center);
//           // painter.translate(0,400);
//     painter.setBrush(Qt::yellow);
//    painter.drawRect(0,0,100,100);
//    painter.eraseRect(lastPoint.x(),lastPoint.y(),(endPoint.x()-lastPoint.x()),(endPoint.y()-lastPoint.y()));

//     //painter.drawRect(300,300,100,100);       //pp.drawImage(0,0,image);
//            //image=copyImage;




//        }
//        if(operater.numOfStretch)
//        {
//            QImage copyImage=image;
//            QPainter pp(&copyImage);
//    //painter.shear(operater.numOfStretch,operater.numOfStretch);

//            pp.shear(operater.numOfStretch,operater.numOfStretch);

//            pp.drawImage(0,0,image);
//            image=copyImage;
//            operater.numOfStretch=0;
//        }

//    //painter.eraseRect(lastPoint.x(),lastPoint.y(),(endPoint.x()-lastPoint.x()),(endPoint.y()-lastPoint.y()));
//    painter.drawImage(0,0,image);
//    update();

}
void paintArea::mousePressEvent(QMouseEvent *event)
{
     int temp =(operater.angle/90)%4;
     QPoint po;
     if(temp==1)
           {
             po.setX(event->pos().y()/operater.scale);
              po.setY(image.size().height()-event->pos().x()/operater.scale);
            }
           else if(temp==2)
           {
               po.setX(image.size().height()-event->pos().x()/operater.scale);
                po.setY(image.size().width()-event->pos().y()/operater.scale);
           }
           else if(temp==3)
           {
               po.setX(image.size().height()-event->pos().y()/operater.scale);
                po.setY(event->pos().x()/operater.scale);
           }
           else
              po=event->pos()/operater.scale;
    if(event->button()==Qt::LeftButton)
    {

        lastPoint=po;
        mouseMark=2;

    }
    if(event->button()==Qt::RightButton)
    {
        mouseMark=1;
    }
}
void paintArea::mouseMoveEvent(QMouseEvent *event)
{
    int temp =(operater.angle/90)%4;
    QPoint po;

    if(temp==1)
          {
            po.setX(event->pos().y()/operater.scale);
             po.setY(image.size().height()-event->pos().x()/operater.scale);
           }
          else if(temp==2)
          {
              po.setX(image.size().height()-event->pos().x()/operater.scale);
               po.setY(image.size().width()-event->pos().y()/operater.scale);
          }
          else if(temp==3)
          {
              po.setX(image.size().height()-event->pos().y()/operater.scale);
               po.setY(event->pos().x()/operater.scale);
          }
          else
             po=event->pos()/operater.scale;
    Dia.mouseChange(po);
    if(mouseMark==1&&Dia.mouse==0)
    {
        setCursor(QCursor(Qt::ArrowCursor));
        Dia.ImaMove(po);

    }
if(Mark==14)
{
    endPoint=po;
    paint(image);
    lastPoint=endPoint;
}

    if(Dia.mouse!=0)
    {
        if(Dia.mouse==1||Dia.mouse==3)
        {
            setCursor(QCursor(Qt::SizeFDiagCursor));
        }
        else
        {
            setCursor(QCursor(Qt::SizeBDiagCursor));

        }
        Dia.Imachange(po);
    }
    if(mouseMark!=0&&Mark!=14)
    {
        endPoint=po;
        if(mouseMark==1)
        {
            endPoint.setX(0);
            endPoint.setY(0);
            lastPoint.setX(0);
            lastPoint.setY(0);
        }

         paint(image);
    }

//    if(event->buttons()&Qt::LeftButton)
//    {
//        endPoint=event->pos();
      //paint(image);
//    }
}
void paintArea::mouseReleaseEvent(QMouseEvent *event)
{
     int temp =(operater.angle/90)%4;
     QPoint po;
     if(temp==1)
           {
             po.setX(event->pos().y()/operater.scale);
              po.setY(image.size().height()-event->pos().x()/operater.scale);
            }
           else if(temp==2)
           {
               po.setX(image.size().height()-event->pos().x()/operater.scale);
                po.setY(image.size().width()-event->pos().y()/operater.scale);
           }
           else if(temp==3)
           {
               po.setX(image.size().height()-event->pos().y()/operater.scale);
                po.setY(event->pos().x()/operater.scale);
           }
           else
              po=event->pos()/operater.scale;
    if(event->button()==Qt::LeftButton)
    {
        endPoint=po;
        mouseMark=0;
        paint(image);


    }

    if(event->button()==Qt::RightButton)
    {


        Dia.Choice(po);
        image=loadImage;
        paint(image);


        //Dia.DeleteIma();
        //Dia.NoChoice();
        //Dia.Shrink();
        mouseMark=0;
        update();

    }

}
void paintArea::paint(QImage &theImage)
{modified=true;

    Input();

    image=loadImage;
    MarkDraw(theImage);
    Dia.ChoiceShow(image);
    if(mouseMark!=0&&Mark!=14)
    {
        Dia.Repeal();
    }
    update();


}
void paintArea::setImageSize(int width,int height)
{
    QImage newImage(width,height,QImage::Format_RGB32);
    image=newImage;
    //loadImage=image;
    image.fill(backcolor);
    //image.fill(backcolor);
    //image=loadImage;
    update();
}
void paintArea::setImageColor(QColor color)
{
    backcolor=color.rgb();
    image.fill(backcolor);
    loadImage=image;
    update();
}
bool paintArea::saveImage(QString &fileName,char *fileFormat)
{
    QImage visibleImage=image;
    if(visibleImage.save(fileName,fileFormat))
    {
        modified=false;
        return true;
    }
    else
    {
        return false;
    }
}
bool paintArea::openImage(QString &fileName)
{

    if(!loadImage.load(fileName))
    {
     return false;
    }
    QSize newSize=loadImage.size();
    image=loadImage;
    setImageSize(newSize.width(),newSize.height());
    Dia.ImageClear();
    modified=false;
    update();
    return true;

}

QSize paintArea::getImageSize()
{
    return image.size()*operater.scale;
}
void paintArea::doPrint()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog *printDialog=new QPrintDialog(&printer,this);
    if(printDialog->exec()==QDialog::Accepted)
    {
        QPainter painter(&printer);
        QRect rect=painter.viewport();
        QSize size=image.size();
        size.scale(rect.size(),Qt::KeepAspectRatio);
       painter.setViewport(rect.x(),rect.y(),size.width(),size.height());
        painter.setWindow(image.rect());
        painter.drawImage(0,0,image);
    }

}


QImage paintArea::getImage()
{
    return image;
}
QColor paintArea::getBackColor()
{
    return backcolor;
}
void paintArea::setMark(int make)
{
    Mark=make;
}
void paintArea::MarkDraw(QImage &theImage)
{
    Dia.Output(theImage);
}
void paintArea::Input()
{
    Dia.Input(Mark,lastPoint,endPoint,penset.return_BrushColor(),penset.return_PenColor(),penset.return_PenWidth(),penset.return_PenStyle());

}
 void paintArea::Repeal()//撤销
 {
     Dia.Repeal();

     //setImageSize(800,800);
     //image.fill(Qt::white);

}
 void  paintArea::ImaCz(int i)
 {
     if(i==0)
     {
         Dia.Enlarge();
     }
     else if(i==1)
     {
         Dia.Shrink();
     }
     else if(i==2)
     {
         Dia.DeleteIma();
     }
     else if(i==3)
     {
         Dia.changColor(penset.return_BrushColor());
     }
     else if(i==4)
     {
         Dia.Overhead();
     }
     else if(i==5)
     {
         Dia.CopyIma();
     }
     else if(i==6)
     {
         Dia.PasteIma();
     }
     else if(i==7)
     {
         Dia.CutIma();
     }
     else if(i==8)
     {
         Dia.NoChoice();
     }
     image=loadImage;
     mouseMark=4;
     paint(image);
     mouseMark=0;
 }
 void paintArea::changImage(QImage &copyImage)
 {
     image=copyImage;
     update();
 }
void paintArea::ClearImage()
{
    Dia.ImageClear();
    loadImage.fill(Qt::white);
}
