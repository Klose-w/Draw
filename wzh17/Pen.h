#ifndef PEN_H
#define PEN_H

#include <QColor>
class Pen
{
public:
    Pen();
    void setPenStyle(Qt::PenStyle style);
    void  setPenWidth(int width);
    void setPenColor(QColor color);
    void setBrushColor(QColor color);

    Qt::PenStyle return_PenStyle();
    int return_PenWidth();
    QColor return_PenColor();
    QColor return_BrushColor();
private:
    QColor penColor;
    QColor brushColor;
    int penWidth;
    Qt::PenStyle penStyle;

};

#endif // PEN_H
