#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void main()
{
	int gd=DETECT,gm;
	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	line(10,10,200,300);
	printf("Hello world\n");
	getch();
}