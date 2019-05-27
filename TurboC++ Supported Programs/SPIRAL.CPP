#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
int a,b;

void li(int x1,int y1,int x2,int y2)
{
    line(a+x1,b-y1,a+x2,b-y2);
}

void spiral1(int x,int y,float deg,float radius,float incr_ang,float incr_r,int clr)
{
    float ang=0,r,rad=3.14159*deg/180;
    float ang2=0,ran2=3.14159*(deg-10)/180;
    int i,x1=0,y1=0,a1=a,b1=b;
    incr_ang=incr_ang*3.14159/180;

    //printf("Hello");
        for(i=0;(x1>-a&&x1<a)||(y1>-b&&y1<b);i++)
        {
            r=radius+incr_r*i;

            x1=r*cos(ang);
            y1=r*sin(ang);
            putpixel(a+x1,b-y1,clr);
            ang=rad+incr_ang+i*3.14/180;
        }
}

void spiral()
{
    double ang,val=0;int i=1;
    double r = 1;
    double a=getmaxx()/2,b=getmaxy()/2;
    double x=-a+1, y=-b+1,sx=2,sy=1;
    for(;i<12;i+=1)
    {
	for(;x<a&&x>-a&&y<b&&y>-b;)
	{
	    val+=20;
	    ang=val*3.142/180;
	    putpixel(a+x,b-y,(i+3)%50);
	    x = r*cos(ang)*(sx*cos(ang)+sy*sin(ang))-a+100;
	    y = r*sin(ang)*(sy*cos(ang)+sx*sin(ang))-b+100;
	    r+=0.005;
	 }
	 x=1;y=1;val=i*5;r=1;

    }
}


void cord()
{
    line(a,0,a,2*b);
    line(0,b,2*a,b);
}

int main()
{
    int gd=DETECT,gm;
    clrscr();
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    a=getmaxx()/2;
    b=getmaxy()/2;
    //cord();
    for(int i=0;1;i+=10)
    {
	spiral1(0,0,i,0,15,0.2,2 );
	spiral1(0,0,i-10,0,15,0.2,0 );
    }
    //spiral();
    getch();
    return 1;
}
