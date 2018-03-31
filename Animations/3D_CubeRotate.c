#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int a,b;
typedef struct vector{
    int x,y,z;
};

typedef struct rotation_vector{
    double xdir,ydir,zdir;
};

typedef struct cube{
    vector *pts;
    int n;                        //No of points on each edge
    int size;                     //Total No of points in cube
};


void li(int x1,int y1,int x2,int y2)
{
    line(a+x1,b-y1,a+x2,b-y2);
}

void drawCubeOrtho(cube c)
{
    for(int i=0;i<c.size/2;i++)
    {
        setcolor(YELLOW);li(c.pts[i].x,c.pts[i].y,c.pts[(i+1)%(c.size/2)].x,c.pts[(i+1)%(c.size/2)].y);
        setcolor(RED);   li(c.pts[c.size/2+i].x,c.pts[c.size/2+i].y,c.pts[c.size/2+(i+1)%(c.size/2)].x,c.pts[c.size/2+(i+1)%(c.size/2)].y);
        setcolor(GREEN);  li(c.pts[i].x,c.pts[i].y,c.pts[c.size/2+i].x,c.pts[c.size/2+i].y);
    }
    setcolor(WHITE);
}

void drawCubePerspective(cube c,vector cop)
{
    for(int i=0;i<c.size/2;i++)
    {
        double u;
        int x1,x2,y1,y2,z1,z2;

        u=-1.0*cop.z/(c.pts[i].z-cop.z);
        x1=cop.x+u*(c.pts[i].x-cop.x);
        y1=cop.y+u*(c.pts[i].y-cop.y);
        u=-1.0*cop.z/(c.pts[(i+1)%(c.size/2)].z-cop.z);
        x2=cop.x+u*(c.pts[(i+1)%(c.size/2)].x-cop.x);
        y2=cop.y+u*(c.pts[(i+1)%(c.size/2)].y-cop.y);
        setcolor(YELLOW);  li(x1,y1,x2,y2);

        u=-1.0*cop.z/(c.pts[c.size/2+i].z-cop.z);
        x1=cop.x+u*(c.pts[c.size/2+i].x-cop.x);
        y1=cop.y+u*(c.pts[c.size/2+i].y-cop.y);
        u=-1.0*cop.z/(c.pts[c.size/2+(i+1)%(c.size/2)].z-cop.z);
        x2=cop.x+u*(c.pts[c.size/2+(i+1)%(c.size/2)].x-cop.x);
        y2=cop.x+u*(c.pts[c.size/2+(i+1)%(c.size/2)].y-cop.y);
        setcolor(RED);  li(x1,y1,x2,y2);

        u=-1.0*cop.z/(c.pts[i].z-cop.z);
        x1=cop.x+u*(c.pts[i].x-cop.x);
        y1=cop.y+u*(c.pts[i].y-cop.y);
        u=-1.0*cop.z/(c.pts[c.size/2+i].z-cop.z);
        x2=cop.x+u*(c.pts[c.size/2+i].x-cop.x);
        y2=cop.y+u*(c.pts[c.size/2+i].y-cop.y);
        setcolor(GREEN);  li(x1,y1,x2,y2);
    }
    setcolor(WHITE);
}

vector rotatePoint(vector v,rotation_vector rv)
{
    int x1=v.x,y1=v.y,z1=v.z;
    double q=3.1415*rv.zdir/180;
    x1 = v.x*cos(q) - v.y*sin(q);
    y1 = v.x*sin(q) + v.y*cos(q);
    z1 = v.z;
    v.x=x1; v.y=y1; v.z=z1;

    q=3.1415*rv.xdir/180;
    y1 = v.y*cos(q) - v.z*sin(q);
    z1 = v.y*sin(q) + v.z*cos(q);
    x1 = v.x;
    v.x=x1; v.y=y1; v.z=z1;

    q=3.1415*rv.ydir/180;
    z1 = v.z*cos(q) - v.x*sin(q);
    x1 = v.z*sin(q) + v.x*cos(q);
    y1 = v.y;
    v.x=x1; v.y=y1; v.z=z1;
    return v;
}


void rotateCube(cube src,cube dest,rotation_vector rv)
{
    for(int i=0;i<src.size;i++)
    {
        dest.pts[i]=rotatePoint(src.pts[i],rv);
    }
}

void cubeTranslate(cube c,vector v)
{
    for(int i=0;i<c.size;i++)
    {
        c.pts[i].x+=v.x;
        c.pts[i].y+=v.y;
        c.pts[i].z+=v.z;
    }
}

int main()
{
    int gd=0,gm;
    initgraph(&gd,&gm,"");
    a=getmaxx()/2;
    b=getmaxy()/2;
    vector v[8],tr;
    v[0].x=0;        v[0].y=0;        v[0].z=0;      v[1].x=100;      v[1].y=0;        v[1].z=0;
    v[2].x=100;      v[2].y=100;      v[2].z=0;      v[3].x=0;        v[3].y=100;      v[3].z=0;
    v[4].x=0;        v[4].y=0;        v[4].z=100;    v[5].x=100;      v[5].y=0;        v[5].z=100;
    v[6].x=100;      v[6].y=100;      v[6].z=100;    v[7].x=0;        v[7].y=100;      v[7].z=100;
    cube a1,b1;
    tr.x=-10;tr.y=20;tr.z=-50;
    b1.pts=(vector*)malloc(a1.size*sizeof(vector));
    rotation_vector rv;
    a1.pts=v;    a1.n=2;    a1.size=8;
    b1.n=a1.n;    b1.size=a1.size;
    rv.xdir=30; rv.ydir=60; rv.zdir=120;
    rotateCube(a1,b1,rv);
    drawCubeOrtho(b1);
    outtextxy(100,200,"This is Orthographic Projection");
    delay(2000);
    cleardevice();
    vector cop;
    cop.x=100;cop.y=100;cop.z=-400;
    drawCubePerspective(b1,cop);
    outtextxy(100,200,"This is Perspective Projection");
    delay(2000);
    rv.xdir=0; rv.ydir=0; rv.zdir=0;
    cleardevice();
    drawCubePerspective(a1,cop);
    while(true)
    {
        outtextxy(100,10,"You can Rotate Cube using keys:-  q,w,e,a,s,d");
        char ch=getch();
        if('w'==ch)            rv.xdir+=10;
        else if('s'==ch)            rv.xdir-=10;
        else if('a'==ch)            rv.ydir+=10;
        else if('d'==ch)            rv.ydir-=10;
        else if(ch=='q')            rv.zdir+=10;
        else if('e'==ch)            rv.zdir-=10;
        else if('x'==ch)            break;
        else continue;
        cleardevice();
        rotateCube(a1,b1,rv);
        drawCubePerspective(b1,cop);
    }
    closegraph();
    return 1;
}
