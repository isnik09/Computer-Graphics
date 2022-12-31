//WRITE A CPP PROGRAM TO SHOW A BALL BOUNCING ANIMATION IN SINE WAVE
#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;
int main() 
{
    int gd,gm;
    gd= DETECT;
    initgraph(&gd,&gm,NULL);
    int maxx =getmaxx();
    int maxy =getmaxy();
    int angle=0;
    maxx = maxx/2;
    maxy = maxy/2;

   
    int sine;
    for(int i=0;i<getmaxx();i+=1)
    {   
        line(0,maxy,getmaxx(),maxy);
        int y = 120*sin(angle*3.141/180);
        y = maxy - y;
        setcolor(CYAN);
        circle(i,y,20);
        delay(10);
        cleardevice();
        angle+=1;
    }
    
    delay(10000);
    
    getch();
    closegraph();
    return 0;
}
