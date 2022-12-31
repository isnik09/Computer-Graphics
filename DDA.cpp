#include <graphics.h>
#include <iostream>
using namespace std;
int main()
{
		int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	float x1,y1,x2,y2;
	cout<<"Enter values of (X1,Y1) & (X2,Y2) "<<endl;
	cin>>x1>>y1>>x2>>y2;
	float ab1 = x2-x1,ab2 = y2-y1;
	float ln;
	if(abs(ab1)>=abs(ab2))
	{
		ln = ab1;
	}
	else
	{
		ln = ab2;
	}
	float dx,dy;
	dx = ab1/ln;
	dy = ab2/ln;
	float i=0;
	float x=x1,y=y1;
	while(i<=ln)
	{
		putpixel(floor(x),floor(y),3);
		x = x+dx;
		y = y+dy;
		i++;
	}
	delay(50000);
	closegraph();
	return 0;
}
