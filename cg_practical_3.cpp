/*Write a CPP Problem to draw the following pattern. Use DDA line and Bresenham's Circle Drawing Algorithm. Apply the concept 
of Encapsulation.*/

#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class pattern
{
	private:
	float x1,y1,x2,y2,step,dx,dy;
	float x,y;
	int xc,yc,R;
	int xi,yi,di,limit,del,del2;
	
	public:
	void ddaline(float x1,float y1,float x2,float y2);
	void bresencircle(int xc,int yc,int R);
};
	

//Function Definitions
void pattern::ddaline(float x1,float y1,float x2,float y2)
{
	//Absolute of Difference and Length
	dx = (x2 - x1);
	dy = (y2 - y1);
	
	if (abs(dx) >= abs(dy))
	{
		step = abs(dx);
	}
	else
	{
		step = abs(dy);
	}
	
	//dx and dy  calculate
	dx = dx/step;
	dy = dy/step;
	
	//Main Looping
	x=x1+0.5;
	y=y1+0.5;
	int i=0;
	
	while(i<=step)
	{
		putpixel(floor(x),floor(y),WHITE);
		x= x + dx;
		y=y + dy;
		i++;
	}
}

void pattern::bresencircle(int xc,int yc,int R)
{
	xi=0;
	yi=R;
	di=2*(1-R);
	limit=0;
	
	while (yi>=limit)
	{
		putpixel(xc+xi, yc+yi,WHITE);
		putpixel(xc-xi, yc+yi,WHITE);
		putpixel(xc-xi, yc-yi,WHITE);
		putpixel(xc+xi, yc-yi,WHITE);
		if (di<0)
		{
			del=(2*di)+(2*yi)-1;
			if (del<=0)
			{
				//mh
				xi+=1;
				di=di+(2*xi)+1;
			}
			else
			{
				//md
				xi+=1;
				yi-=1;
				di=di+(2*xi)-(2*yi)+2;
			}
		}
		else if (di>0)
		{
			del2=(2*di)-(2*xi)-1;
			if (del2<=0)
			{
				//md
				xi+=1;
				yi-=1;
				di=di+(2*xi)-(2*yi)+2;
			}
			else
			{
				//mv
				yi-=1;
				di=di-(2*yi)+1;
			}
		}
		else if (di==0)
		{
			//md
			xi+=1;
			yi-=1;
			di=di+(2*xi)-(2*yi)+2;
		}
	}
}

int main()
{	
	int gd,gm;
	int ch;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	
	//Logical Division of Page
	setcolor(BLUE);
	line(0,240,640,240);
	line(320,0,320,480);
	
	//Object Creation
	pattern p;

	cout<<"\tMENU"<<endl;
	cout<<"Enter 1 for Triangle Pattern\nEnter 2 for Rectangle Pattern\nEnter 3 for Both Patterns"<<endl;
	cin>>ch;

	//SwitchCase		
	switch (ch)
		{
		case 1: //Triangle Pattern
				//Drawing Small Circle
				p.bresencircle(320,240,50);
	
				//Drawing Triangle
				p.ddaline(235,290,405,290);
				p.ddaline(405,290,320,140);
				p.ddaline(320,140,235,290);

				//Drawing Bigger Circle
				p.bresencircle(320,240,100);
				break;

		case 2: //Rectangle Pattern
				//Circle
				p.bresencircle(200,125,67);
				
				//Diamond
				p.ddaline(200,50,350,125);
				p.ddaline(200,50,50,125);
				p.ddaline(50,125,200,200);
				p.ddaline(200,200,350,125);

				//Rectangle
				p.ddaline(50,50,350,50);
				p.ddaline(50,50,50,200);
				p.ddaline(50,200,350,200);
				p.ddaline(350,50,350,200);
				break;
				
		case 3: //Both Together
				//Drawing Small Circle
				p.bresencircle(480,120,50);
	
				//Drawing Triangle
				p.ddaline(480,20,392,170);
				p.ddaline(392,170,568,170);
				p.ddaline(568,170,480,20);

				//Drawing Bigger Circle
				p.bresencircle(480,120,100);
				
				//1st Quadrant
				//Circle
				p.bresencircle(165,116,72);
				
				//Diamond
				p.ddaline(165,30,30,115);
				p.ddaline(30,115,165,200);
				p.ddaline(165,200,300,115);
				p.ddaline(300,115,165,30);

				//Rectangle
				p.ddaline(30,30,300,30);
				p.ddaline(300,30,300,200);
				p.ddaline(300,200,30,200);
				p.ddaline(30,200,30,30);
				break;
		
		default: cout<<"Wrong Input !!";
				break;
		}
	
	delay(50000);
	getch();
	closegraph();
	return 0;
}
