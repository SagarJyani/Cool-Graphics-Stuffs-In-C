#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
int a,b;

void display_hands(int sec,int min,int hour,int r)
{
    int x_min,y_min,x_sec,y_sec,x_hour,y_hour;
    x_min=r*cos(3.14/180*(-6*min+90))*2/3;
    y_min=r*sin(3.14/180*(-6*min+90))*2/3;
    x_sec=r*cos(3.14/180*(-6*sec+90));
    y_sec=r*sin(3.14/180*(-6*sec+90));
    x_hour=r*cos(3.14/180*(-30*hour+90))/3;
    y_hour=r*sin(3.14/180*(-30*hour+90))/3;
    printf("hour:-%d\tmin:-%d\tsec:%d\n",hour,min,sec);
    line(a,b,a+x_sec,b-y_sec);setcolor(2);
    line(a,b,a+x_min,b-y_min);setcolor(3);
    line(a,b,a+x_hour,b-y_hour);setcolor(WHITE);
}

void display_clock(int r)
{
    int min =50,sec=02,hour=11;
    while(true)
    {
        if(sec==60)
        {
            sec=0;
            min++;
        }
        if(min==60)
        {
            min=0;
            hour++;
        }
        if(hour==12)
        {
            hour=0;
            hour++;
        }
        cleardevice();
        display_hands(sec,min,hour,r);
        sec++;
        circle(a,b,r*1.1);
        delay(1000);
    }
}

int main()
{
    int gd=DETECT,gm,x=0,y=0,r=200;
    initgraph(&gd,&gm,"c:\\tc3\\bgi");
    a=getmaxx()/2;
    b=getmaxy()/2;
    line(a,0,a,2*b);
    line(0,b,2*a,b);

    display_clock(r);
    getch();
    return 1;
}
