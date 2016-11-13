#include "music.h"
#include "Qsound"
#include "ui_mainwindow.h"
#include "Qdebug"
#include "QDir"

music::music()
{
//    QString dir=QCoreApplication ::applicationDirPath();
//    QString filename=(dir+"/sound/s1.wav");
//    qDebug()<<dir;//用来给你看看那个难搞的地址在什么地方，资源放过去吧
//    QSound *sound = new QSound(filename);
}
void music::musicplay()
{
    QApplication::beep();
}
void music::soundplay1()
{

      QString filename=("D:/sound/s1.wav");

      QSound *sound = new QSound(filename);
      music();
      sound->play();
      sound->setLoops (10);
     //  void QSound::setLoops ( 1 );
       //void QSound::stop ("c:/Users/cie/Desktop/untitled/untitled/sound/s.wav") ;
    //QSoundbells("c:\Users\cie\Desktop\untitled\untitled\sound/儿童歌曲-虫儿飞.wav");
   // bells.play();
}
void music::soundplay2()
{
    QString filename=("D:/sound/s2.wav");

    QSound *sound = new QSound(filename);
    music();
    sound->play();
    sound->setLoops (10);

}
void music::soundplay3()
{
    QString filename=("D:/sound/s3.wav");
    QSound *sound = new QSound(filename);
    music();
    sound->play();
    sound->setLoops (10);

}
void music::soundstop()
{


    QSound *sound;

    sound->stop ();


}
