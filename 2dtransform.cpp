/* 2-D Transformations */

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;


void draw(int n,float arr1[20][3])
{   	
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
    int j;
    setcolor(GREEN);
    for(int i=0;i<n;i++)
    {   
        j=i+1;
        if(j!=0)
        {
            line(arr1[i][1],arr1[i][2],arr1[j][1],arr1[j][2]);
        }	
        
        else
        {
            break;
        }
    }
    line(arr1[n-1][1],arr1[n-1][2],arr1[0][1],arr1[0][2]);
}

int main()
{
	
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
    
    
    
    int n;
    cout<<"Enter no. of vertices:"<<endl;
    cin>>n;
    float arr1[n][3];
    for(int i =0; i<n;i++)
    {
        cout<<"Enter coordinates for vertices :"<<endl;
        cin>>arr1[i][1]>>arr1[i][2];
        arr1[i][3]=1;
    }
    draw(n,arr1);
    
    delay(10000);
    
 	getch();
	closegraph();
	return 0;
}


