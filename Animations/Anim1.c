#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int a,b,x,y;

void cord()
{
    line(a,0,a,2*b);
    line(0,b,2*a,b);
}

void circ(int x,int y,int r)
{
    circle(a+x,b-y,r);
}

int animate()
{
    int rm=200,r=0,xc,yc,t=90;
    double r1;
    double rad;
    double r__;
    double rad_;
    int rm1=200,r_1=0,xc1,yc1,t1=90;
    do
    {
        t=t%360;
        rad=3.14*t/180;
        r1=3.14*(t-90)/360;
        r=abs(rm*sin(r1)/2);
        xc=(rm-r)*cos(rad);
        yc=(rm-r)*sin(rad);
        circ(xc,yc,r);
        //printf("%d\t%d\t%d\n",xc,yc,r);
        //getch();
        //delay(10);
        t+=2;

        t1=t+180;
        t1=t1%360;
        rad_=3.14*t1/180;
        r__=3.14*(t1-90)/360;
        r_1=abs(rm1*sin(r__)/2);
        xc1=(rm1-r_1)*cos(rad_);
        yc1=(rm1-r_1)*sin(rad_);
        setcolor(BLACK);
        circ(xc1,yc1,r_1);
        setcolor(WHITE);
        //printf("%d\t%d\t%d\n",xc,yc,r);
        //getch();
        cord();
        delay(10);
        //printf("%d\n",rm);
    }while(t!=90);
    setcolor(BLACK);
    t=270;
    do
    {
        t=t%360;
        rad=3.14*t/180;
        r1=3.14*(t-90)/360;
        r=abs(rm*sin(r1)/2);
        xc=(rm-r)*cos(rad);
        yc=(rm-r)*sin(rad);
        circ(xc,yc,r);
        //printf("%d\t%d\t%d\n",xc,yc,r);
        //getch();
        setcolor(WHITE);cord();setcolor(BLACK);
        delay(10);
        t+=2;
    }while(t!=90);
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc3\\bgi");
    //line(10,10,200,300);
    a=getmaxx()/2;
    b=getmaxy()/2;
    cord();
    animate();
    getch();
    return 1;
}
