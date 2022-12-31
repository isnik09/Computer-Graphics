//write a cpp program to draw the following pattern use dda line and bresenham circle drawing algo. apply concept of encapsulation
#include<iostream>
#include<graphics.h>
using namespace std;
class cg
{
private:
	int i;
	float dx,dy,steps,x,y,xi,yi;
public:
	void drawline(float,float,float,float,char);
	
};

void cg::drawline(float x1,float y1,float x2,float y2,char color)
{
	
	dx=x2-x1;
	dy=y2-y1;
	
	if(fabs(dx)>fabs(dy))
	{
		steps=fabs(dx);
	}
	else
	{
		steps=fabs(dy);
	}
	xi=dx/steps;
	yi=dy/steps;
	x=x1;
	y=y1;
	for(i=0;i<steps;i++)
	{
		putpixel(floor(x),floor(y),color);
		x=x+xi;
		y=y+yi;
	}
}


class brecircle
{
    int Xc, Yc, Xi, Yi, R, Di, limit, d,d_;
    public:
    void mycircle(int, int, int);
    void mh();
    void md();
    void mv();

};
void brecircle :: mycircle(int Xc, int Yc, int R)
{
    limit= 0;
    Xi=0;
    Yi=R;
    Di=2*(1-R);
    while(Yi>=limit)
    {
    putpixel(Xc+Xi, Yc+Yi, BLUE);

    putpixel(Xc+Xi, Yc-Yi,BLUE);

    putpixel(Xc-Xi,Yc-Yi,BLUE);

    putpixel(Xc-Xi,Yc+Yi,BLUE);


    if(Di<0)
    {
        d=((2*Di) + (2*Yi) - 1);

        if(d<=0)
            mh();

        else
            md();
    }

    else if(Di>0)
    {
        d_=((2*Di) - (2*Xi) - 1);

        if(d_<=0)
            md();

        else
            mv();

    }

    else if(Di==0)
            md();
    }

}

void  brecircle :: mh()        
{
Xi= Xi + 1;
    Di= Di + 2*Xi +1;
}

void  brecircle :: mv()        
{
    Yi= Yi - 1;
    Di= Di - 2*Yi +1;
}

void  brecircle :: md()        
{
    Xi= Xi + 1;
    Yi= Yi-1;
    Di= Di + 2*Xi -2*Yi + 2;
}

int main()
{
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,NULL);
cg c1;
brecircle b1;

//line(0,240,640,240);
//line(320,0,320,480);

//RECTANGLE
c1.drawline(50,50,350,50,RED);
c1.drawline(50,50,50,200,RED);
c1.drawline(50,200,350,200,RED);
c1.drawline(350,50,350,200,RED);

//DIAMOND
c1.drawline(200,50,350,125,RED);
c1.drawline(200,50,50,125,RED);
c1.drawline(50,125,200,200,RED);
c1.drawline(200,200,350,125,RED);


b1.mycircle(200,125,67);


delay(100000);
closegraph();
return 0;
}
