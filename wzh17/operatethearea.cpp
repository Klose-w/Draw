#include "operatethearea.h"

operateTheArea::operateTheArea(QWidget *parent) :
    QWidget(parent)
{
    scale=1;
    angle=0;
    numOfStretch=-0.2;
}
void operateTheArea::zoomIn()
{
    scale*=1.2;
    //update();
}
void operateTheArea::zoomOut()
{
    scale/=1.2;
   // update();
}
void operateTheArea::zoom_No()
{
    scale=1;
    numOfStretch=0;
    angle=0;
    //update();

}
void operateTheArea::Rotate()
{
    angle+=90;
    //update();
}
void operateTheArea::Stretch()
{
    numOfStretch=0.2;
   // update();
}

