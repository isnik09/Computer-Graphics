#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
	int gd,gm;
	gd = DETECT;
	initgraph(&gd,&gm,NULL);
	setcolor(RED);
	line(320,0,320,480);
	line(0,240,640,240);
	line(10,120,300,80);
	line(330,120,620,80);
	line(10,360,300,320);
	line(330,360,620,320);
	delay(10000);
	closegraph();
	return 0;
	 
}
