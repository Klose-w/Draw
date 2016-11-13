#ifndef OPERATETHEAREA_H
#define OPERATETHEAREA_H

#include <QWidget>
class operateTheArea : public QWidget
{
    Q_OBJECT
public:
    explicit operateTheArea(QWidget *parent = 0);

    void zoomIn();
    void zoomOut();
    void zoom_No();
    void Rotate();
    void Stretch();
   // void Clear();

    qreal scale;//比例
    int angle;  //旋转角度
    qreal numOfStretch;//拉伸量

};

#endif // OPERATETHEAREA_H
