#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
	int gd,gm;
	gd = DETECT;
	initgraph(&gd,&gm,NULL);
	setcolor(BLUE);
	circle(150,150,35);
	setcolor(RED);
	rectangle(100,100,200,200);
	line(100,150,150,100);
	line(150,100,200,150);
	line(200,150,150,200);
	line(150,200,100,150);
	delay(10000);
	closegraph();
	return 0;
	 
}
