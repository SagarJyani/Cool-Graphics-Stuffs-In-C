#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
#include<malloc.h>
int a,b,x,y;

void li(int x1,int y1,int x2,int y2)
{
    line(a+x1,b-y1,a+x2,b-y2);
}

void cord()
{
    line(a,0,a,2*b);
    line(0,b,2*a,b);
}

void circ(int x,int y,int r)
{
    circle(a+x,b-y,r);
}

void animate(int n,int* r,int* n_pts)
{
    int **x=(int**)malloc(n*sizeof(int*));
    int **y=(int**)malloc(n*sizeof(int*));
    float **t1=(float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
    {
        x[i]=(int*)malloc(n_pts[i]*sizeof(int));
        y[i]=(int*)malloc(n_pts[i]*sizeof(int));
        t1[i]=(float*)malloc(n_pts[i]*sizeof(float));

        //setcolor(YELLOW);circ(0,0,r[i]);setcolor(WHITE);

        x[i][0]=r[i]*cos(3.14*t1[i][0]/180);
        y[i][0]=r[i]*sin(3.14*t1[i][0]/180);

        for(int j=1;j<n_pts[i];j++)
        {
            t1[i][j]=(t1[i][j-1]+1.0*360/(n_pts[i]));
            if(t1[i][j]>360) t1[i][j]-=360;
            //printf("%f\n",t1[i]);
            x[i][j]=r[i]*cos(3.14*t1[i][j]/180);
            y[i][j]=r[i]*sin(3.14*t1[i][j]/180);
        }

    }
    //printf("Hello\n");
    int loop=1;
    setcolor(CYAN);
    for(i=0;i<n;i++)
    {
	for(int j=0;j<=i;j++)
	{
	    //printf("Loop%d:",loop++);
	    //delay(100);
	    for(int i1=0;i1<n_pts[i];i1++)
	    {
		for(int j1=0;j1<n_pts[j];j1++)
		{
		    float diff=abs(t1[i][i1]-t1[j][j1]);
		    //printf("%f\t%f\t%f\t",diff,t1[i][i1],t1[j][j1]);
		    //if(diff<=90.0){
		     //   printf("done");
		     if(((x[i][i1]-x[j][j1])*(x[i][i1]-x[j][j1])+(y[i][i1]-y[j][j1])*(y[i][i1]-y[j][j1]))<=r[i]*r[i])
			li(x[i][i1],y[i][i1],x[j][j1],y[j][j1]);
		    //}
		    //printf("\n");
		}
	    }
	}
    }
}

int main()
{
    int gd=DETECT,gm,inc=10;
    clrscr();
    int n=4,r[4]={50,100,150,200},n_pts[4]={13,7,22,17};
    int* a1=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) a1[i]=1;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    //line(10,10,200,300);
    a=getmaxx()/2;
    b=getmaxy()/2;
    //animate(n,r,n_pts);
    //cord();
    while(1)
    {
        animate(n,r,n_pts);
        for(int i=0;i<n;i++)
        {
            if(r[i]==200)
                a1[i]=-1;
            if(r[i]==0)
                a1[i]=1;
            r[i]+=a1[i]*inc;
            //printf("radius%d:-%d \tinc:%d\n",i,r[i],a1[i]);
        }
        delay(10);
        cleardevice();
        //cord();
    }
    getch();
    return 1;
}
