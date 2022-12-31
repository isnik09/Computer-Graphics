#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
void koch(int x1,int y1,int x2, int y2,int iter)
{
    float angle=60*M_PI/180;
    int x3=((2*x1)+x2)/3;
    int x4=(x1+2*(x2))/3;
    int y3=(2*(y1)+y2)/3;
    int y4=(y1+2*y2)/3;
    int theta;
   
    int x=x3+(x4-x3)*cos(angle)+(y4-y3)*sin(angle);
    int y=y3-(x4-x3)*sin(angle)+(y4-y3)*cos(angle);
    
    if(iter>0)
    {
        delay(10);
        koch(x1,y1,x3,y3,iter-1);
        delay(10);
        koch(x3,y3,x,y,iter-1);
        delay(10);
        koch(x,y,x4,y4,iter-1);
        delay(10);
        koch(x4,y4,x2,y2,iter-1);
        
    }
    
    else
    {
           
            line(x1,y1,x3,y3);
            line(x3,y3,x,y);
            line(x,y,x4,y4);
            line(x4,y4,x2,y2);
          
    }
}

int main()
{
    int gd,gm;
    gd =DETECT;
    
    initgraph(&gd,&gm,NULL);
    setcolor(CYAN);
    koch(200,266,100,100,3);
    koch(100,100,300,100,3);
    koch(300,100,200,266,3);
    delay(1000);
    return 0;
    
}
