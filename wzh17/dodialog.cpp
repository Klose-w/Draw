#include "dodialog.h"
#include "ui_dodialog.h"
#include <QColorDialog>
Dodialog::Dodialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dodialog)
{
    ui->setupUi(this);
    backColor=Qt::white;
}

Dodialog::~Dodialog()
{
    delete ui;
}
int Dodialog::getWidth()
{
    return ui->widthSpinBox->text().toInt();
}
int  Dodialog::getHeight()
{
    return ui->heightSpinBox->text().toInt();
}
QColor Dodialog::getbackColor()
{
    return backColor;
}


void Dodialog::on_pushButton_clicked()
{
   QColor newcolor=QColorDialog::getColor();
   if(newcolor.isValid())
   {
       backColor=newcolor;
       QPalette palette=ui->textBrowser->palette();
       palette.setColor(QPalette::Base,backColor);
       ui->textBrowser->setPalette(palette);
       update();
   }

}

