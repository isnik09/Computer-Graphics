#include<iostream>
using namespace std;
class shape
{
	private:
		float x1,y1,x2,y2;
	public:
		
		line(float x1,float y1,float x2,float y2)
		{
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
		}
} 
int main()
{	int gd,gm;
	gd = DETECT;
	initgraph(&gd,&gm,NULL);
	int a;
	cout<<"ENter no. of lines"<<endl;
	cin>>a;
	for(a;a>0;a--)
	{
			
	}
	
}
