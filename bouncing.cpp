//Write a C++ Program to implement bouncing ball using sine wave form
#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;
int main()
{
	int gd=DETECT,gm; 
initgraph(&gd,&gm,NULL);

	initgraph(&gd,&gm,NULL);
	
	int angle=0;
	double x,y;
	
	line(320,0,320,480);
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
		
	//Generate sine wave
	for(x=0;x<getmaxx();x+=1)
	{
		setcolor(CYAN);
		line(320,0,320,480);
		line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	
	
		//Calculate y for corresponding x
		y=100*sin(angle*3.14/180);
		y=getmaxy()/2-y;
		
		setcolor(YELLOW);
		circle(x,y,30);
		delay(50);
		cleardevice();
		angle+=1;
	}
	
	delay(5000);
	getch();
	closegraph();
	return 0;
}
