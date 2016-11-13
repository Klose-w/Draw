#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "paintArea.h"
#include <QScrollArea>
#include <QComboBox>
#include <ui_mainwindow.h>
#include "mainwindow.h"
#include "dodialog.h"
#include <QPainter>
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <Qsound>
#include "music.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int qwidth;
    int qheight;
    QColor col;
    //
    void createColorComboBox(QComboBox *comboBox);//构建颜色组合框

//文件
    void doOpen();
void doNew();
bool doFileSave();
bool doFileSaveAs();
void Clear();
private slots:

    void changeImage();
    void on_action_triggered();


    void on_penColorComboBox_currentIndexChanged(int index);

    void on_spinBox_valueChanged(int arg1);

    void on_penColorComboBox_2_currentIndexChanged(const QString &arg1);

    void on_tool_triggered();

    void on_actionSave_triggered();

    void on_brushColorComboBox_currentIndexChanged(int index);

    void on_actionSave_another_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();


    void closeEvent(QCloseEvent *);
    void on_actionPrint_triggered();

    void on_action_2_triggered();


    void on_action_in_triggered();

    void on_action_out_triggered();

    void on_action_no_triggered();

    void on_action_rotate_triggered();



    void on_action_stretch_triggered();

    void on_action_clear_triggered();

    void on_penColorComboBox_3_currentIndexChanged(const QString &arg1);

    void on_action_fangda_triggered();

    void on_action_suoxiao_triggered();

    void on_action_clean_triggered();

    void on_action_changecolor_triggered();

    void on_action_dingzhi_triggered();

    void on_action_copy_triggered();

    void on_action_zhantie_triggered();

    void on_action_jianqie_triggered();

    void on_action_guding_triggered();

    void on_actionMusic1_triggered();

    void on_actionMusic2_triggered();

    void on_actionMusic3_triggered();

    void on_actionStop_triggered();

private:
    Ui::MainWindow *ui;
    paintArea *area;
    QScrollArea *scrollArea;

//文件
    bool isSaved;
    QString curFile;
    bool maybeSave();
    bool saveFile(QString &fileName);
};

#endif // MAINWINDOW_H
