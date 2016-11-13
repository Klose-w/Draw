#include "Pen.h"

Pen::Pen()
{
     penColor=Qt::black;
     penStyle=Qt::SolidLine;
     brushColor=Qt::black;
      penWidth=1;
}
void Pen::setPenColor(QColor color)
{
     penColor=color;
}
void Pen::setPenStyle(Qt::PenStyle style)
{
  penStyle=style;
}
void Pen::setBrushColor(QColor color)
{
     brushColor=color;
}
void  Pen::setPenWidth(int width)
{
    penWidth=width;
}

Qt::PenStyle Pen::return_PenStyle()
{
    return penStyle;
}

int Pen::return_PenWidth()
{
    return penWidth;
}

QColor Pen::return_PenColor()
{
    return penColor;
}

QColor Pen::return_BrushColor()
{
    return brushColor;
}
