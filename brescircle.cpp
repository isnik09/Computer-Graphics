#include <iostream>
#include <graphics.h>
using namespace std;
class circles
{	
	public:
	int xi,yi,di,xc,yc,r,d,d1;
	void getval();
	void putval();
	void draw_cir();
};
void circles::getval()
{
	cout<<"enter coordinate x and y that is center:";
	cin>>xc>>yc;
	cout<<"enter radius of circle";
	cin>>r;
}
void circles::putval()
{
	cout<<"center point is: "<<xc<<yc;
	cout<<"radius is"<<r;
}

void circles:: draw_cir()
{
	xi=0;
	yi=r;
	di =2*(1-r);
	int limit =0;
	while (yi>=limit)
	{
		putpixel((xc+xi),(yc+yi),RED);
		putpixel((xc-xi),(yc+yi),RED);
		putpixel((xc-xi),(yc-yi),RED);
		putpixel((xc+xi),(yc-yi),RED);
		if(di<0){		
			d =2*(di+yi-1);
			if(d<0){
				xi+=1;
				di = di+(2*xi)+1;}
				
			else if(di>0){
				d1 =(2*di)-(2*xi)-1;
				if(d1<=0){                                                                                                                                          
					xi+=1;
					yi-=1;
					di =di+(2*xi)-(2*yi)+2;}
				else{
					yi-=1;
					di =di-(2*yi)+1;}
				}
			else if(di=0){
				xi+=1;
				yi-=1;
				di =di+(2*xi)-(2*yi)+2;
				
			}
			}	
		}
		
}
	

int main()
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	circles c;
	c.getval();
	c.putval();
	c.draw_cir();
	delay(10000);
	return 0;
}











