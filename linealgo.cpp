 #include<graphics.h>
#include<iostream>
using namespace std;
int main()
{
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,NULL);

int x1,x2,y1,y2;
cout<<"Enter value x1,y1,x2,y2 respc:"<<endl;
cin>>x1;
cin>>y1;
cin>>x2;
cin>>y2;
int ab_1= abs(x2-x1),ab_2= abs(y2-y1);
int ln;
if (ab_1>=ab_2)
	{	ln=ab_1;
	}
else{
	ln=ab_2;
	}
float dx,dy;
dx=ab_1/ln;
dy=ab_2/ln;
int i=0;
int x=x1,y=y1;
while (i<=ln)
	{
		putpixel(int(x),int(y),3);
		x=x+dx;
		y=y+dy;
		i++;
	}
	delay(50000);
	closegraph();
	return 0 ;
	}
	
	
	
	
	
	
