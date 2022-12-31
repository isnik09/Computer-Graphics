#include<graphics.h>
#include<iostream>
using namespace std;
int main()
{
	int gd,gm;
	gd = DETECT;
	initgraph(&gd,&gm,NULL);
	setcolor(BLUE); 
	line(50,50,10,100);
	delay(5000);
	closegraph();
	return 0;
	

}
