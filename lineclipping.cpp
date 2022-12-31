#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;
static int CENTER=0,TOP=8,LEFT=1,RIGHT=2,BOTTOM=4,INSIDE=0;
static int x_min,y_min,x_max,y_max;  
int computeCode(double x, double y)
{
	
	int code = INSIDE;

	if (x < x_min){ 
		code |= LEFT;}
	else if (x > x_max){ 
		code |= RIGHT;}
	if (y < y_min){ 
		code |= BOTTOM;}
	else if (y > y_max){
	          code |= TOP;} 

	return code;
	
}

void cohenSutherlandClip(double x1, double y1,double x2, double y2)
{
	
	int code1 = computeCode(x1, y1);
	int code2 = computeCode(x2, y2);

	
	bool accept = false;

	while (true) {
		if ((code1 == 0) && (code2 == 0)) {
			
			accept = true;
			break;
		}
		else if (code1 & code2) {
			
			break;
		}
		else {
			
			int code_out;
			double x, y;

			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;

			if (code_out & TOP) {
				
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code_out & BOTTOM) {
				
				x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
				y = y_min;
			}
			else if (code_out & RIGHT) {
				
				y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
				x = x_max;
			}
			else if (code_out & LEFT) {
				
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}

			
			if (code_out == code1) {
				x1 = x;
				y1 = y;
				code1 = computeCode(x1, y1);
			}
			else {
				x2 = x;
				y2 = y;
				code2 = computeCode(x2, y2);
			}
		}
		
	}
	
	 
	if (accept) {
	          cleardevice();
		cout << "Line accepted from " << x1 << ", "
			<< y1 << " to " << x2 << ", " << y2 << endl;
			rectangle(x_min,y_min,x_max,y_max);
			line(x1,y1,x2,y2);
		
	}
	else
		{cout << "Line rejected" << endl;}
          
}
	





int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	int x2,x3,y2,y3;
	
                    
          
	cout<<"enter the co-ordinate of rectangle:";
          cin>>x_min>>y_min;
          cout<<"enter the co-ordinate of other end point of rectangle:";
          cin>>x_max>>y_max;
          rectangle(x_min,y_min,x_max,y_max);
          cout<<"enter the line co-ordinate:";
          cin>>x2>>y2>>x3>>y3;
          line(x2,y2,x3,y3);
          cohenSutherlandClip(x2,y2,x3,y3);
         
        
	delay(5000);
	closegraph();
	return 0 ;
	}
