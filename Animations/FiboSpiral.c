#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int a,b;

void li(int x1,int y1,int x2,int y2)
{
    line(a+x1,b-y1,a+x2,b-y2);
}

void square(int x,int y,int size,int m)
{
    li(x,y,x+size*m,y);
    li(x,y,x,y+size*m);
    li(x+size*m,y+size*m,x,y+size*m);
    li(x+size*m,y+size*m,x+size*m,y);
}

int main()
{
    int gd=0,gm;
    initgraph(&gd,&gm,"");
    a=getmaxx()/2;
    b=getmaxy()/2;
    setcolor(RED);
    li(-a,0,a,0);
    setcolor(GREEN);
    li(0,-b,0,b);
    setcolor(WHITE);
    int x=0,y=0,multiplier=1,i=0;
    int fibo[2]={0,1};
    while(abs(x)<=a||abs(y)<=b)
    {
        int c=fibo[0]+fibo[1];
        fibo[0]=fibo[1];
        fibo[1]=c;
        i=fibo[1]-fibo[0];
        getch();//delay(1000);
        square(x,y,fibo[0],multiplier);
        printf("%d\t%d\t%d\t\t( %d , %d )\n",fibo[0],fibo[1],c,x,y);x-=c*multiplier;y-=i*multiplier;

        c=fibo[0]+fibo[1];
        fibo[0]=fibo[1];
        fibo[1]=c;
        getch();//delay(1000);
        square(x,y,fibo[0],multiplier);
        printf("%d\t%d\t%d\t\t( %d , %d )\n",fibo[0],fibo[1],c,x,y);y-=c*multiplier;

        c=fibo[0]+fibo[1];i=fibo[0];
        fibo[0]=fibo[1];
        fibo[1]=c;
        getch();//delay(1000);
        square(x,y,fibo[0],multiplier);
        printf("%d\t%d\t%d\t\t( %d , %d )\n",fibo[0],fibo[1],c,x,y);x+=fibo[0]*multiplier;

        c=fibo[0]+fibo[1];
        fibo[0]=fibo[1];
        fibo[1]=c;
        i=fibo[1]-fibo[0];
        getch();//delay(1000);
        square(x,y,fibo[0],multiplier);
        printf("%d\t%d\t%d\t\t( %d , %d )\n",fibo[0],fibo[1],c,x,y);y+=fibo[0]*multiplier;x-=i*multiplier;
    }
    getch();
    return 0;
}
