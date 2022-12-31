/*SCAN-LINE FILL ALGORITHM


Name : MANSI DINESH NERKAR
roll no. -Comp SE-B 77
*/


#include <iostream>
#include <graphics.h>
using namespace std;

int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
    int n,i,j,k,dy,dx;
    int y,temp;
    cout<<"enter number of edges:";
    cin>>n;
    int x1[n],y1[n],xi[1000];
    float slope[1000];

    for(i=0;i<n;i++)
    {
        cout<<"Enter coordinates(x,y):";
        cin>>x1[i]>>y1[i];       
    }
    x1[n]=x1[0];
    y1[n]=y1[0];
    for(i=0;i<n;i++)
    {
        line(x1[i],y1[i],x1[i+1],y1[i+1]);
    }
    for(i=0;i<n;i++)
    {
        dx=x1[i+1]-x1[i];
        dy=y1[i+1]-y1[i];
        if(dy==0){slope [i]=1.0;}
        if(dx==0){slope [i]=0.0;}
        if((dx!=0) && (dy!=0))
        {
            slope[i]=(float) dx/dy;
        }
    }
    for(y=0;y<480;y++)
    {
        k=0;
        for(i=0;i<n;i++)
        {
            if(((y1[i]<=y)&&(y1[i+1]>y)) || ((y1[i]>y)&&(y1[i+1]<=y)))
            {
                xi[k]=(int)(x1[i]+slope[i]*(y-y1[i]));
                k++;
            
            }
        }
    

    for(i=0;i<k-1;i++)
    {
        for(j=0;j<k-1;j++)
        {
            if(xi[j]>xi[i+1])
            {
                temp=xi[j];
                xi[j]=xi[j+1];
                xi[j+1]=temp;
            }
        }
    }

    setcolor(GREEN);
    for(i=0;i<k;i+=2)
    {
        line(xi[i],y,xi[i+1]+1,y);
    }
    delay(5);
} 
    getch();
    closegraph();
    return 0;
}
