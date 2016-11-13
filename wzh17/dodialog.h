#ifndef DODIALOG_H
#define DODIALOG_H

#include <QDialog>

namespace Ui {
class Dodialog;
}

class Dodialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dodialog(QWidget *parent = 0);
    ~Dodialog();
    //设置画布
    int getWidth();
    int getHeight();
    QColor getbackColor();


private slots:

    void on_pushButton_clicked();

private:
    Ui::Dodialog *ui;
    QColor backColor;
};

#endif // DODIALOG_H
