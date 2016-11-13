#include "diagram.h"

Diagram::Diagram()
{
    first=NULL;
    mouse=0;
}
void Diagram::Input(int id, QPoint x, QPoint y, QColor col, QColor pcol, int wid, Qt::PenStyle sty)
{
    Ima *Node=new Ima(id,x,y,col,pcol,wid,sty);
    Node->next=first;
    first=Node;
}
void Diagram::Output(QImage &theImage)
{
    Transposition();
    Ima *ptr;
    ptr=second;
    while(ptr!=NULL)
    {
        if(ptr->Id==0||ptr->Id==14)
        {
            cshape one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid,ptr->Sty);
            one.draw(theImage);

        }
        else if(ptr->Id==1)
        {
            Circle one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);

        }
        else if(ptr->Id==2)
        {
            Triangle one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);
        }
        else if(ptr->Id==3)
        {
            Rect one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);
        }
        else if(ptr->Id==4)
        {
            Trapezoid one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);
        }
        else if(ptr->Id==5)
        {
            Arrows one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);
        }
        else if(ptr->Id==6)
        {
            Pentagon one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);
        }
        else if(ptr->Id==7)
        {
            Star one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);
        }
        else if(ptr->Id==8)
        {
            Hexagon one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);
        }
        else if(ptr->Id==9)
        {
            Curve one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);
        }
        else if(ptr->Id==10)
        {
            Ring one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);
        }
        else if(ptr->Id==11)
        {
            FCStar one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);
        }
        else if(ptr->Id==12)
        {
            Diamond one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);
        }
        else if(ptr->Id==13)
        {
            TArrows one(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid);
            one.draw(theImage);
        }
        ptr=ptr->next;

    }
}
void Diagram::Transposition()
{
    Ima *ptr;
    ptr=first;
    second=NULL;
    while(ptr!=NULL)
    {
        Ima *Node=new Ima(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid,ptr->Sty);
        Node->next=second;
         second=Node;
        ptr=ptr->next;
    }
}
void Diagram::Repeal()
{
    Ima *ptr;
    ptr=first;
    first=ptr->next;
    delete ptr;
}
void Diagram::Choice(QPoint cp)
{
    Ima *ptr;
    ptr=first;
    while(ptr!=NULL)
    {
        int ssxx=ptr->X.x();;
        int ssyy=ptr->X.y();
        int eexx=ptr->Y.x();
        int eeyy=ptr->Y.y();
        if(ssxx>eexx)
        {
            int temp;
            temp=ssxx;
            ssxx=eexx;
            eexx=temp;
         }
        if(ssyy>eeyy)
        {
            int temp;
            temp=ssyy;
            ssyy=eeyy;
            eeyy=temp;
         }
        if(cp.x()<=eexx&&cp.x()>=ssxx&&cp.y()<=eeyy&&cp.y()>=ssyy&&ptr->Id!=14&&ptr->Mark==0)
        {
            xx=ptr->X;
            yy=ptr->Y;
            break;
         }
        else
        {
           ptr=ptr->next;
        }
    }
    if(ptr==NULL)
    {
      xx.setX(0);
      xx.setY(0);
      yy.setX(1);
      yy.setY(1);
     }
}
void Diagram::ChoiceShow(QImage &theImage)
{
    QPoint S,L,E,R;
    S.setX(xx.x());
    S.setY(xx.y());
    L.setX(xx.x());
    L.setY(yy.y());
    E.setX(yy.x());
    E.setY(yy.y());
    R.setX(yy.x());
    R.setY(xx.y());
    cshape Line1(0,S,L,Qt::red,Qt::red,3,Qt::DashLine);
    Line1.draw(theImage);
    cshape Line2(0,L,E,Qt::red,Qt::red,3,Qt::DashLine);
    Line2.draw(theImage);
    cshape Line3(0,E,R,Qt::red,Qt::red,3,Qt::DashLine);
    Line3.draw(theImage);
    cshape Line4(0,R,S,Qt::red,Qt::red,3,Qt::DashLine);
    Line4.draw(theImage);
}
void Diagram::ImaMove(QPoint cp)
{
    Ima *ptr;
    ptr=first;
    while(ptr!=NULL)
    {
       if((xx.x()==ptr->X.x())&&(ptr->X.y()==xx.y())&&(ptr->Y.x()==yy.x())&&(ptr->Y.y()==yy.y()))
        {
            int wx=(ptr->X.x()+ptr->Y.x())/2-cp.x();
            int wy=(ptr->X.y()+ptr->Y.y())/2-cp.y();
            ptr->X.setX(ptr->X.x()-wx);
            ptr->X.setY(ptr->X.y()-wy);
           // ptr->Lx=ptr->Lx-wx;
           // ptr->Ly=ptr->Ly-wy;
            ptr->Y.setX(ptr->Y.x()-wx);
            ptr->Y.setY(ptr->Y.y()-wy);
            //ptr->Rx=ptr->Rx-wx;
            //ptr->Ry=ptr->Ry-wy;
            xx.setX(ptr->X.x());
            xx.setY(ptr->X.y());
            yy.setX(ptr->Y.x());
            yy.setY(ptr->Y.y());

            //start.x=ptr->Sx;
            //start.y=ptr->Sy;
            //end.x=ptr->Ex;
            //end.y=ptr->Ey;
             break;
        }
        else
        {
            ptr=ptr->next;
        }

    }
}
void Diagram::Imachange(QPoint cp)
{
    Ima *ptr;
    ptr=first;
        while(ptr!=NULL)
        {
            if((xx.x()==ptr->X.x())&&(ptr->X.y()==xx.y())&&(ptr->Y.x()==yy.x())&&(ptr->Y.y()==yy.y()))
            {

                int ssxx=ptr->X.x();;
                int ssyy=ptr->X.y();
                int eexx=ptr->Y.x();
                int eeyy=ptr->Y.y();
                if(ssxx<eexx&&ssyy<eeyy)
                {
                    if(mouse==1)
                    {
                        ptr->X.setY(cp.y());
                        ptr->X.setX(cp.x());
                        //ptr->Lx=cp.x;
                        //ptr->Ry=cp.y;
                    }
                    else if(mouse==2)
                    {
                        ptr->Y.setY(cp.y());
                        ptr->X.setX(cp.x());
                       // ptr->Sx=cp.x;
                        //ptr->Ey=cp.y;
                    }
                    else if(mouse==3)
                    {
                        ptr->Y.setY(cp.y());
                        ptr->Y.setX(cp.x());
                        //ptr->Rx=cp.x;
                        //ptr->Ly=cp.y;

                    }
                    else if(mouse==4)
                    {
                        ptr->X.setY(cp.y());
                        ptr->Y.setX(cp.x());
                        //ptr->Ex=cp.x;
                        //ptr->Sy=cp.y;
                    }
                }
                else if(ssxx<eexx&&ssyy>eeyy)
                {
                    if(mouse==1)
                    {
                        ptr->X.setY(cp.y());
                        ptr->Y.setX(cp.x());
                        //ptr->Sx=cp.x;
                        //ptr->Ey=cp.y;
                    }
                    else if(mouse==2)
                    {
                        ptr->X.setY(cp.y());
                        ptr->X.setX(cp.x());
//                        ptr->Rx=cp.x;
//                        ptr->Ly=cp.y;
                    }
                    else if(mouse==3)
                    {
                        ptr->Y.setY(cp.y());
                        ptr->X.setX(cp.x());
//                        ptr->Ex=cp.x;
//                        ptr->Sy=cp.y;

                    }
                    else if(mouse==4)
                    {
                        ptr->Y.setY(cp.y());
                        ptr->Y.setX(cp.x());
//                        ptr->Lx=cp.x;
//                        ptr->Ry=cp.y;
                    }

                }
                else if(ssxx>eexx&&ssyy>eeyy)
                {
                    if(mouse==1)
                    {
                        ptr->Y.setY(cp.y());
                        ptr->Y.setX(cp.x());
//                        ptr->Rx=cp.x;
//                        ptr->Ly=cp.y;
                    }
                    else if(mouse==2)
                    {
                        ptr->X.setY(cp.y());
                        ptr->Y.setX(cp.x());
//                        ptr->Ex=cp.x;
//                        ptr->Sy=cp.y;
                    }
                    else if(mouse==3)
                    {
                        ptr->X.setY(cp.y());
                        ptr->X.setX(cp.x());
//                        ptr->Lx=cp.x;
//                        ptr->Ry=cp.y;

                    }
                    else if(mouse==4)
                    {
                        ptr->Y.setY(cp.y());
                        ptr->X.setX(cp.x());
//                        ptr->Sx=cp.x;
//                        ptr->Ey=cp.y;
                    }
                }
                else if(ssxx>eexx&&ssyy<eeyy)
                {
                    if(mouse==1)
                    {
                        ptr->Y.setY(cp.y());
                        ptr->X.setX(cp.x());
//                        ptr->Ex=cp.x;
//                        ptr->Sy=cp.y;
                    }
                    else if(mouse==2)
                    {
                        ptr->Y.setY(cp.y());
                        ptr->Y.setX(cp.x());
//                        ptr->Lx=cp.x;
//                        ptr->Ly=cp.y;
                    }
                    else if(mouse==3)
                    {
                        ptr->X.setY(cp.y());
                        ptr->Y.setX(cp.x());
//                        ptr->Sx=cp.x;
//                        ptr->Ey=cp.y;

                    }
                    else if(mouse==4)
                    {
                        ptr->X.setY(cp.y());
                        ptr->X.setX(cp.x());
//                        ptr->Rx=cp.x;
//                        ptr->Ly=cp.y;
                    }

                }
                xx.setX(ptr->X.x());
                xx.setY(ptr->X.y());
                yy.setX(ptr->Y.x());
                yy.setY(ptr->Y.y());
//                    start.x=ptr->Sx;
//                    start.y=ptr->Sy;
//                    end.x=ptr->Ex;
//                    end.y=ptr->Ey;
                break;
            }
            else
            {
                ptr=ptr->next;
            }
        }
}
void Diagram::mouseChange(QPoint cp)
{
            int ssxx=xx.x();;
            int ssyy=xx.y();
            int eexx=yy.x();
            int eeyy=yy.y();
            if(ssxx>eexx)
            {
                int temp;
                temp=ssxx;
                ssxx=eexx;
                eexx=temp;
            }
            if(ssyy>eeyy)
            {
                int temp;
                temp=ssyy;
                ssyy=eeyy;
                eeyy=temp;
            }
        if(cp.x()<=ssxx+5&&cp.x()>=ssxx-5&&cp.y()<=ssyy+5&&cp.y()>=ssyy-5)
        {


            mouse=1;
        }
        else if(cp.x()<=ssxx+3&&cp.x()>=ssxx-3&&cp.y()<=eeyy+3&&cp.y()>=eeyy-3)
        {

            mouse=2;
        }
        else if(cp.x()<=eexx+3&&cp.x()>=eexx-3&&cp.y()<=eeyy+3&&cp.y()>=eeyy-3)
        {

            mouse=3;
         }
        else if(cp.x()<=eexx+3&&cp.x()>=eexx-3&&cp.y()<=ssyy+3&&cp.y()>=ssyy-3)
        {

            mouse=4;
        }
        else
        {
            mouse=0;
        }
}
void Diagram::Enlarge()
{
    Ima *ptr;
     ptr=first;
    while(ptr!=NULL)
    {
        if((xx.x()==ptr->X.x())&&(ptr->X.y()==xx.y())&&(ptr->Y.x()==yy.x())&&(ptr->Y.y()==yy.y()))
         {

            int wx=(ptr->X.x()+ptr->Y.x())/2;
            int wy=(ptr->X.y()+ptr->Y.y())/2;
            int r1=ptr->Y.x()-wx;
            int r2=ptr->Y.y()-wy;
            ptr->X.setX(wx-r1*1.1);
            ptr->X.setY(wy-r2*1.1);
//            ptr->Lx=wx-r1*1.1;
//            ptr->Ly=wy+r2*1.1;
            ptr->Y.setX(wx+r1*1.1);
            ptr->Y.setY(wy+r2*1.1);
//            ptr->Rx=wx+r1*1.1;
//            ptr->Ry=wy-r2*1.1;
            xx.setX(ptr->X.x());
            xx.setY(ptr->X.y());
            yy.setX(ptr->Y.x());
            yy.setY(ptr->Y.y());
//            start.x=ptr->Sx;
//            start.y=ptr->Sy;
//            end.x=ptr->Ex;
//            end.y=ptr->Ey;
            break;
        }
        else
        {
            ptr=ptr->next;
        }
    }
}
void Diagram::Shrink()
{
    Ima *ptr;
     ptr=first;
    while(ptr!=NULL)
    {
        if((xx.x()==ptr->X.x())&&(ptr->X.y()==xx.y())&&(ptr->Y.x()==yy.x())&&(ptr->Y.y()==yy.y()))
         {

            int wx=(ptr->X.x()+ptr->Y.x())/2;
            int wy=(ptr->X.y()+ptr->Y.y())/2;
            int r1=ptr->Y.x()-wx;
            int r2=ptr->Y.y()-wy;
            ptr->X.setX(wx-r1*0.9);
            ptr->X.setY(wy-r2*0.9);
//            ptr->Lx=wx-r1*1.1;
//            ptr->Ly=wy+r2*1.1;
            ptr->Y.setX(wx+r1*0.9);
            ptr->Y.setY(wy+r2*0.9);
//            ptr->Rx=wx+r1*1.1;
//            ptr->Ry=wy-r2*1.1;
            xx.setX(ptr->X.x());
            xx.setY(ptr->X.y());
            yy.setX(ptr->Y.x());
            yy.setY(ptr->Y.y());
//            start.x=ptr->Sx;
//            start.y=ptr->Sy;
//            end.x=ptr->Ex;
//            end.y=ptr->Ey;
            break;
        }
        else
        {
            ptr=ptr->next;
        }
    }
}
void Diagram::changColor(QColor col)
{
    Ima *ptr;
    ptr=first;
    int ssxx=xx.x();;
    int ssyy=xx.y();
    int eexx=yy.x();
    int eeyy=yy.y();
    if(ssxx>eexx)
    {
        int temp;
        temp=ssxx;
        ssxx=eexx;
        eexx=temp;
    }
    if(ssyy>eeyy)
    {
        int temp;
        temp=ssyy;
        ssyy=eeyy;
        eeyy=temp;
    }
    while(ptr!=NULL)
    {
        if((xx.x()==ptr->X.x())&&(ptr->X.y()==xx.y())&&(ptr->Y.x()==yy.x())&&(ptr->Y.y()==yy.y()))
        {
            ptr->Col=col;
            break;

        }
        else
        {
            ptr=ptr->next;
        }
     }

}
void Diagram::DeleteIma()
{
    Ima *ptr,*ptr1;
    ptr=first;
    if(first==NULL)
    {
        exit(0);
    }
    if((xx.x()==ptr->X.x())&&(ptr->X.y()==xx.y())&&(ptr->Y.x()==yy.x())&&(ptr->Y.y()==yy.y()))
    {
            first=ptr->next;
//            xx.setX(0);
//            xx.setY(0);
//            yy.setX(0);
//            yy.setY(0);
    }
    ptr1=ptr->next;
    while(ptr1!=NULL)
    {
            if((xx.x()==ptr1->X.x())&&(ptr1->X.y()==xx.y())&&(ptr1->Y.x()==yy.x())&&(ptr1->Y.y()==yy.y()))
            {

                ptr->next=ptr1->next;
                delete ptr1;
//                xx.setX(0);
//                xx.setY(0);
//                yy.setX(0);
//                yy.setY(0);
                break;

            }
            else
            {
                ptr1=ptr1->next;
                ptr=ptr->next;
            }
    }

}
void Diagram::CopyIma()
{
    Ima *ptr;
    ptr=first;
    while(ptr!=NULL)
    {
        if((xx.x()==ptr->X.x())&&(ptr->X.y()==xx.y())&&(ptr->Y.x()==yy.x())&&(ptr->Y.y()==yy.y()))
        {

            copy=new Ima(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid,ptr->Sty);
            break;

        }
        else
        {
            ptr=ptr->next;
        }
    }
}
void Diagram::PasteIma()
{
    if(copy!=NULL)
    {
        Ima *Node =new Ima(copy->Id,copy->X,copy->Y,copy->Col,copy->Pcol,copy->Wid,copy->Sty);
        Node->next=first;
        first=Node;
    }
}
void Diagram::CutIma()
{
    Ima *ptr;
    ptr=first;
    while(ptr!=NULL)
    {
        if((xx.x()==ptr->X.x())&&(ptr->X.y()==xx.y())&&(ptr->Y.x()==yy.x())&&(ptr->Y.y()==yy.y()))
        {

            copy=new Ima(ptr->Id,ptr->X,ptr->Y,ptr->Col,ptr->Pcol,ptr->Wid,ptr->Sty);
            break;

        }
        else
        {
            ptr=ptr->next;
        }
    }
    Ima *Node =new Ima(copy->Id,copy->X,copy->Y,copy->Col,copy->Pcol,copy->Wid,copy->Sty);
    Node->next=first;
    first=Node;
}
void Diagram::Overhead()
{
    Ima *ptr,*ptr1;
    ptr=first;
    ptr1=ptr->next;
    while(ptr1!=NULL)
    {
        if((xx.x()==ptr->X.x())&&(ptr->X.y()==xx.y())&&(ptr->Y.x()==yy.x())&&(ptr->Y.y()==yy.y()))
        {

            ptr->next=ptr1->next;
            ptr1->next=first;
            first=ptr1;
            break;

        }
        else
        {
            ptr1=ptr1->next;
            ptr=ptr->next;
        }
    }
}
void Diagram::NoChoice()
{
    Ima *ptr;
    ptr=first;
    while(ptr!=NULL)
    {
        if((xx.x()==ptr->X.x())&&(ptr->X.y()==xx.y())&&(ptr->Y.x()==yy.x())&&(ptr->Y.y()==yy.y()))
        {
            ptr->Mark=1;
            break;

        }
        else
        {
            ptr=ptr->next;
        }
    }
}
 void Diagram::ImageClear()
 {
     first=NULL;
 }
