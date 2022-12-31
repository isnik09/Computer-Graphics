//Cohen Sutherland Line Clipping Algorithm

#include<iostream>
#include<graphic.h>
using namespace std;

class lineClip
{
	private:
	int ABOVE=8,BELOW=4,RIGHT=2,LEFT=1;
	int xl,yl,xh,yh,x1,y1,x2,y2,xn,yn;
	int code,code_p1,code_p2;
	float m;
	int flag,temp;
	
	public:
	void clipping();
	int getCode(int,int);
	
};

int lineClip::getCode(int x,int y)
{
	code=0;
	if(y>yh){
		code|=ABOVE;
	}
	else if(y<yl){
		code|=BELOW;
	}
	else if(x<xl){
		code|=LEFT;
	}
	else if(x>xh){
		code|=RIGHT;
	}
	return code;
}
	
	

void lineClip::clipping()
{
	//Step 1- Draw Rectangle
	cout<<"Enter the Coordinates of Rectangle - "<<endl;	
	cout<<"Enter the Bottom Left x-coordinate :";
	cin>>xl;
	cout<<"Enter the Bottom Left y-coordinate :";
	cin>>yl;
	cout<<"Enter the Top Right x-coordinate :";
	cin>>xh;
	cout<<"Enter the Top Right y-coordinate :";
	cin>>yh;
	setcolor(YELLOW);
	rectangle(xl,yl,xh,yh);
	
	//Step 2-Draw Line 
	cout<<"Enter the Coordinates of Line -"<<endl;
	cout<<"Enter the start point x- coordinate :";
	cin>>x1;
	cout<<"Enter the start point y- coordinate :";
	cin>>y1;
	cout<<"Enter the end point x- coordinate :";
	cin>>x2;
	cout<<"Enter the end point y- coordinate :";
	cin>>y2;
	setcolor(WHITE);
	line(x1,y1,x2,y2);
	delay(1000);
	
	//Step 3- Get Outcodes
	code_p1=getCode(x1,y1);
	code_p2=getCode(x2,y2);
	
	//Step 4- Find Intersections
	flag=0;
	while (1)
	{
		m=(float)(y2-y1)/(float)(x2-x1);
	
		if (code_p1==0 && code_p2==0)
		{
			flag=1;
			break;
		}
		else if((code_p1 & code_p2)!=0)
		{
			break;
		}
		else
		{
			if(code_p1==0){
				temp=code_p2;
			}
			else{
				temp=code_p1;
			}
			
			if(temp & ABOVE){
				yn=yh;
				xn=x1+((yh-y1)/m);
			}
			else if(temp & BELOW)
			{
				yn=yl;
				xn=x1+((yl-y1)/m);
			}
			else if(temp & LEFT)
			{
				xn=xl;
				yn=y1+m*(xl-x1);
			}
			else if(temp & RIGHT)
			{
				xn=xh;
				yn=y1+m*(xh-x1);
			}

				delay(1000);
		
			//Step 5-Replace End Points with Intesection points and Update Region Code 
			if(temp==code_p1)
			{
				x1=int(xn);
				y1=int(yn);
				code_p1=getCode(x1,y1);
			}
			else
			{
				x2=int(xn);
				y2=int(yn);
				code_p2=getCode(x2,y2);
			}
		}
	}
	
	//Step 6 - Drawing Clipped Line
	cleardevice();
	delay(1000);
	setcolor(YELLOW);
	rectangle(xl,yl,xh,yh);
	delay(1000);
	
	if(flag==1)
	{
		setcolor(WHITE);
		line(x1,y1,x2,y2);
		cout<<"Clipped Line is from (",x1,",",y1,") to (",x2,",",y2,")"<<endl;
		delay(1000);
		getch();
	}
	else if (flag==0)
	{
		cout<<"Line Rejected"<<endl;
	}
}
	
	
int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	
	lineClip l;
	l.clipping();
	
	getch();
	closegraph();
	return 0;
}
