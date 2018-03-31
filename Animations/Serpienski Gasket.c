#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
int a,b;

void li(double x1,double y1,double x2,double y2)
{
    line(a+(int)x1,b-(int)y1,a+(int)x2,b-(int)y2);
}

void fractal(double a[][2])
{
    double d=sqrt((a[0][0]-a[1][0])*(a[0][0]-a[1][0])+(a[0][1]-a[1][1])*(a[0][1]-a[1][1]));
    if(d<=1)
        return;
    li(a[0][0],a[0][1],a[1][0],a[1][1]);
    li(a[1][0],a[1][1],a[2][0],a[2][1]);
    li(a[2][0],a[2][1],a[0][0],a[0][1]);
    //delay(10);
    double p1[3][2],p2[3][2],p3[3][2];

    p1[0][0]=a[0][0];               p1[0][1]=a[0][1];
    p1[1][0]=(a[1][0]+a[0][0])/2;  p1[1][1]=(a[1][1]+a[0][1])/2;
    p1[2][0]=(a[0][0]+a[2][0])/2;  p1[2][1]=(a[0][1]+a[2][1])/2;

    p2[1][0]=a[1][0];               p2[1][1]=a[1][1];
    p2[0][0]=(a[0][0]+a[1][0])/2;  p2[0][1]=(a[0][1]+a[1][1])/2;
    p2[2][0]=(a[1][0]+a[2][0])/2;  p2[2][1]=(a[2][1]+a[1][1])/2;

    p3[2][0]=a[2][0];               p3[2][1]=a[2][1];
    p3[1][0]=(a[1][0]+a[2][0])/2;  p3[1][1]=(a[1][1]+a[2][1])/2;
    p3[0][0]=(a[2][0]+a[0][0])/2;  p3[0][1]=(a[2][1]+a[0][1])/2;
    fractal(p1);
    fractal(p2);
    fractal(p3);
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd, &gm, "");
    int x=300,y=300;
    int r = rand() % 3;
    int xm = getmaxx()/2,ym = getmaxy()/2;
    a = getmaxx()/2-200;
    b = getmaxy()/2+200;
    double arr[6][2] = {0,0,400/2,800*0.866/2,800/2,0};
    for(double a=0;a<15000;a++)
    {
        putpixel(x+xm-200,ym-y+200,5);
        r = rand() % 3;
        x = (x+arr[r][0])/2;
        y = (y+arr[r][1])/2;
        //delay(1);
    }
    delay(1000);
    //closegraph(ALL_WINDOWS);
    initgraph(&gd, &gm, "");
    fractal(arr);
    getch();
    return 1;
}
