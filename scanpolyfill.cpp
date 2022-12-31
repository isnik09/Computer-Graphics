#include <iostream>
#include <graphics.h>
using namespace std;


class polydraw  //BASE CLASS
{   protected:
	int x[10];
	int y[10];
	int y_min =1000;
	int y_max =0;
	
	public:
		void get_x_coordinates(int);
		void get_y_coordinates(int);
		void draw(int);
	    int n=0;	
};

void polydraw::get_x_coordinates(int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"Enter value of x"<<i<<endl;
		cin>>x[i];
	}
}

void polydraw::get_y_coordinates(int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"Enter value of y"<<i<<endl;
		cin>>y[i];
		if(y[i]>y_max)
		{
			y_max = y[i];
		}
		if(y[i]<y_min)
		{
		    y_min =y[i];
		}
	}
}
void polydraw::draw(int n)
{	int j;
	for(int i =0; i<n; i++)
	{	
		j = i+1;
		if(j!=n)
		{
		line(x[i],y[i],x[j],y[j]);
		}
	}
	line(x[n-1],y[n-1],x[0],y[0]);

}
class polyfill : public polydraw //INHERITED CLASS
{   
   float dx,dy;
   int temp;
   int xi[100];
   float m[10];
   public:
   void scan_line_fill(); 

};
void polyfill::scan_line_fill()
{
    for(int i=0;i<n;i++)
    {
        dx = x[i+1]-x[i];
        dy = y[i+1]-y[i];
        if(dx ==0)
        {
            m[i]=0;
        }
        else if(dy==0)
        {
            m[i]=1;
        }
        else
        {
            m[i]=(dx/dy);
        }
        
    }
    int k;
    for (int p=y_max;p>y_min;p-- )
    {   
        k=0;
        for(int i=0;i<n;i++)
        {
             if(( (y[i]<=p) && (y[i+1]>p)) || ((y[i]>p) && (y[i+1]<=p) ))
              {
                  xi[k]=x[i]+m[i]*(p-y[i]);     
                  k++;
              }
              
        }
         
         for(int j=0;j<k-1;j++)  
          {
              for(int i=0;i<k-1;i++)
              {
                  if(xi[i]>xi[i+1])   
                  {
                      temp = xi[i];
                      xi[i] = xi[i+1];
                      xi[i+1] = temp;
                  }
              }
          }
          
          for(int i=0;i<k;i=i+2)   
          {
               setcolor(GREEN);

              line(xi[i], p ,xi[i+1], p);  
              delay(10);      
          }
          
         
                
    }
    
    
    
}



int main()
{
	int gd,gm,n;
	gd = DETECT;
	initgraph(&gd,&gm, NULL);
	polydraw p1;
	polyfill p2;
	cout<<"Enter no. of vertices:"<<endl;
	cin>>n;
	p1.get_x_coordinates(n);
	p1.get_y_coordinates(n);
	p1.draw(n);
	p2.scan_line_fill();
	
	delay(100000);
	closegraph();
	return 0;
}



