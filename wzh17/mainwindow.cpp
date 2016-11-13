#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dodialog.h"
#include <QPainter>
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <Qsound>
#include "music.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    resize(1000,500); //主窗口
     area=new paintArea;
     scrollArea=new QScrollArea;
     scrollArea->setBackgroundRole(QPalette::Dark); //scrollArea为dark
    scrollArea->setWidget(area);
   scrollArea->widget()->setMinimumSize(600,500); //scrollArea主窗口大小
    setCentralWidget(scrollArea);  //加载到主窗口

    //改变颜色
    createColorComboBox(ui->brushColorComboBox);
    createColorComboBox(ui->penColorComboBox);


    isSaved=false;
    curFile=tr("未命名.png");
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changeImage()
{
    Dodialog dlg;
    if(dlg.exec()==QDialog::Accepted)
    {
        qwidth=dlg.getWidth();
        qheight=dlg.getHeight();
        area->setImageSize(qwidth,qheight);
        scrollArea->widget()->resize(qwidth,qheight);
        col=dlg.getbackColor();
        area->setImageColor(col);

}
}
void MainWindow::doOpen()
{
if(maybeSave())
{
    QString fileName=QFileDialog::getOpenFileName(this,
                                                  tr("打开文件"),QDir::currentPath());
    if(!fileName.isEmpty())
    {
        area->openImage(fileName);
        scrollArea->widget()->resize(area->getImageSize());
        isSaved=true;
        curFile=fileName;
    }
}

}
void MainWindow::doNew()
{

    if(maybeSave())
    {
        Dodialog dlg;
        if(dlg.exec()==QDialog::Accepted)
        {
            int width=dlg.getWidth();
            int height=dlg.getHeight();
            area->setImageSize(width,height);
            scrollArea->widget()->resize(width,height);
            area->setImageColor(dlg.getbackColor());

        }
    }
}
bool MainWindow::maybeSave()
{
    if(area->isModified())
    {
        QMessageBox::StandardButton box;
    box=QMessageBox::warning(this,tr("保存文件"),tr("图片已变，是否保存？"),
    QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    if(box==QMessageBox::Yes)
    {
        return doFileSave();
    }
    else if(box==QMessageBox::Cancel)
    {
      return false;
    }
}
return true;

}
bool MainWindow::doFileSave()
{
    if(isSaved)
    {
        return saveFile(curFile);
    }
    else
        return doFileSaveAs();
}
bool MainWindow::saveFile(QString &fileName)
{
   if(area->saveImage(fileName,"png"))
   {
       isSaved=true;
       return true;
   }
   else{
   return false;
   }

}
bool MainWindow::doFileSaveAs()
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("另存为"),curFile);
    if(fileName.isEmpty())
    {
        return false;
    }
    else
        return saveFile(fileName);
}
void MainWindow::on_action_triggered()
{
    changeImage();
}
void MainWindow::createColorComboBox(QComboBox *comboBox)
{
    QPixmap pixmap(16,16);
    QPainter painter(&pixmap);
    painter.fillRect(0,0,16,16,Qt::black); //先绘制一个16*16 的小图片，然后给其涂色
    comboBox->addItem(QIcon(pixmap),"黑色",QColor(Qt::black));//再用该图片作为组合框条目的图标
    painter.fillRect(0,0,16,16,Qt::white);
    comboBox->addItem(QIcon(pixmap),"白色",QColor(Qt::white));
    painter.fillRect(0,0,16,16,Qt::red);
    comboBox->addItem(QIcon(pixmap),tr("红色"),QColor(Qt::red));
    painter.fillRect(0,0,16,16,Qt::green);
    comboBox->addItem(QIcon(pixmap),tr("绿色"),QColor(Qt::green));
    painter.fillRect(0,0,16,16,Qt::blue);
    comboBox->addItem(QIcon(pixmap),tr("蓝色"),QColor(Qt::blue));
    painter.fillRect(0,0,16,16,Qt::yellow);
    comboBox->addItem(QIcon(pixmap),"黄色",QColor(Qt::yellow));
  //  painter.fillRect(0,0,16,16,);
    comboBox->addItem("其他颜色");
}
void MainWindow::on_penColorComboBox_currentIndexChanged(int index)
{
    if(ui->penColorComboBox->itemData(index,Qt::UserRole).value<QColor>()=="其他颜色")
        {
        QColor newcolor=QColorDialog::getColor();
        if(newcolor.isValid())
        {
          area->penset.setPenColor(newcolor);
        }
    }
    else{
    QColor color =ui->penColorComboBox->itemData(index,Qt::UserRole).value<QColor>();

    area->penset.setPenColor(color);
    }
}
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    area->penset.setPenWidth(arg1);
}
void MainWindow::on_penColorComboBox_2_currentIndexChanged(const QString &arg1)
{
    if(arg1=="实线")
        area->penset.setPenStyle(Qt::SolidLine);
    else if(arg1=="点线")
        area->penset.setPenStyle(Qt::DotLine);
    else if(arg1=="虚线")
        area->penset.setPenStyle(Qt::DashLine);
    else if(arg1=="点虚线")
        area->penset.setPenStyle(Qt::DashDotLine);
}
void MainWindow::on_tool_triggered()
{
    ui->dockWidget->show();
}
void MainWindow::on_brushColorComboBox_currentIndexChanged(int index)
{
    if(ui->brushColorComboBox->itemData(index,Qt::UserRole).value<QColor>()=="其他颜色")
    {
        QColor newcolor=QColorDialog::getColor();
        if(newcolor.isValid())
        {
          area->penset.setBrushColor(newcolor);
        }

    }
    else{
    QColor color =ui->brushColorComboBox->itemData(index,Qt::UserRole).value<QColor>();

    area->penset.setBrushColor(color);
    }
}
void MainWindow::on_actionSave_triggered()
{
    music button;
    button.musicplay();
   doFileSave();
}
void MainWindow::on_actionSave_another_triggered()
{
    music button;
    button.musicplay();
    doFileSaveAs();
}
void MainWindow::on_actionOpen_triggered()
{
    music button;
    button.musicplay();
    doOpen();
}
void MainWindow::on_actionNew_triggered()
{
    music button;
    button.musicplay();
    doNew();
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(maybeSave())
    {
        qApp->quit();
    }
    else
    {
        event->ignore();
    }
}
void MainWindow::on_actionPrint_triggered()
{
    music button;
    button.musicplay();
    area->doPrint();
}
void MainWindow::Clear()
{ 
    QImage newImage(area->getImage().width(),area->getImage().height(),QImage::Format_RGB32);
    newImage.fill(area->getBackColor());
   area->changImage(newImage);
   area->ClearImage();
}
void MainWindow::on_action_in_triggered()
{
    music button;
    button.musicplay();
    area->operater.zoomIn();
    scrollArea->widget()->resize(area->getImageSize());
    area->update();
}
void MainWindow::on_action_out_triggered()
{
    music button;
    button.musicplay();
     area->operater.zoomOut();
     area->update();
}
void MainWindow::on_action_no_triggered()
{
       music button;
       button.musicplay();
       area->operater.zoom_No();
       area->update();
}
void MainWindow::on_action_rotate_triggered()
{
    music button;
    button.musicplay();
    area->operater.Rotate();
    area->update();
}
void MainWindow::on_action_stretch_triggered()
{
     music button;
     button.musicplay();
     area->operater.Stretch();

     scrollArea->widget()->resize(area->getImageSize());

     area->update();
}
void MainWindow::on_action_clear_triggered()
{
    music button;
    button.musicplay();
   this->Clear();
}
void MainWindow::on_penColorComboBox_3_currentIndexChanged(const QString &arg1)
{
    if(arg1=="直线")
            area->setMark(0);
        else if(arg1=="圆")
           area->setMark(1);
        else if(arg1=="三角形")
            area->setMark(2);
        else if(arg1=="矩形")
           area->setMark(3);
        else if(arg1=="梯形")
           area->setMark(4);
        else if(arg1=="尖头")
            area->setMark(5);
        else if(arg1=="五边形")
            area->setMark(6);
        else if(arg1=="五角星")
            area->setMark(7);
        else if(arg1=="六边形")
           area->setMark(8);
        else if(arg1=="曲线")
           area->setMark(9);
        else if(arg1=="圆环")
           area->setMark(10);
        else if(arg1=="四角星")
           area->setMark(11);
        else if(arg1=="菱形")
           area->setMark(12);
        else if(arg1=="箭头")
           area->setMark(13);
        else if(arg1=="涂鸦")
           area->setMark(14);
}
void MainWindow::on_action_fangda_triggered()
{
    music button;
    button.musicplay();
    area->ImaCz(0);
}
void MainWindow::on_action_suoxiao_triggered()
{
    music button;
    button.musicplay();
     area->ImaCz(1);
}
void MainWindow::on_action_clean_triggered()
{
    music button;
    button.musicplay();
     area->ImaCz(2);
}
void MainWindow::on_action_changecolor_triggered()
{
    music button;
    button.musicplay();
     area->ImaCz(3);
}
void MainWindow::on_action_dingzhi_triggered()
{
    music button;
    button.musicplay();
     area->ImaCz(4);
}
void MainWindow::on_action_copy_triggered()
{
    music button;
    button.musicplay();
     area->ImaCz(5);
}
void MainWindow::on_action_zhantie_triggered()
{
    music button;
    button.musicplay();
     area->ImaCz(6);
}
void MainWindow::on_action_jianqie_triggered()
{
    music button;
    button.musicplay();
     area->ImaCz(7);
}
void MainWindow::on_action_guding_triggered()
{
    music button;
    button.musicplay();
     area->ImaCz(8);
}

void MainWindow::on_actionMusic1_triggered()
{
    music button;
    button.soundplay1();
}

void MainWindow::on_actionMusic2_triggered()
{
    music button;
    button.soundplay2();
}

void MainWindow::on_actionMusic3_triggered()
{
    music button;
    button.soundplay3();
}

void MainWindow::on_actionStop_triggered()
{
    music button;
    button.soundstop();
}
