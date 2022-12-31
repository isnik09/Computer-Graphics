/*IMPLEMENT BALL BOUNCING ANIMATION USING SINE WAVE
Name : MANSI DINESH NERKAR
roll no. -Comp SE-B 77
*/



#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

class bounce
{
	public:
	int angle ;
	
	void sine()
	{
		for(int i=0;i<640;i++)
		{
			line(0,240,640,240);
			int y=120*sin(angle*3.141/180);
			y=240-y;
			circle(i,y,20);
			setcolor(RED);
			circle(i,y,20);
        		delay(10);
        		cleardevice();
        		angle+=1;
        	}
    }
 				
};
int main() 
{
    int gd,gm;
    gd= DETECT;
    initgraph(&gd,&gm,NULL);
    bounce b1;
    b1.sine();
    
    
    
    delay(10000);
    
    getch();
    closegraph();
    return 0;
}


