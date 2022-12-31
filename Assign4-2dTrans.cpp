/* 2-D Transformations */

#include<iostream>
#include<graphics.h>
using namespace std;


void draw(int n,poly[][3])
{
	
	line(poly[0][0],poly[0][1],poly[1][0],poly[1][1]);
	line(poly[1][0],poly[1][1],poly[2][0],poly[2][1]);
	line(poly[2][0],poly[2][1],poly[0][0],poly[0][1]]);
}

void get_coordinates(int n,int poly[n][3])
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"Enter the value at ["<<i+1<<","<<j+1<<"] :";
			cin>>poly[i][j];
			poly[i][3]=1;
		}
	}
	setcolor(RED);
	draw(n,poly[n][3]);
}


void multiply(int n;int transform[][3],int poly[][3],int result[][3])
{

	for (int i=0;i<n;i++)
	{
		for (int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				result[i][j]+=transform[i][k]*poly[k][j];
			}
		}
	}
			
}


void translate(int n,int transform[n][3],int poly[][3])
{
	int tx,ty;
	cout<<"Enter X-Translation factor,tx :";
	cin>>tx;
	cout<<"Enter Y-Translation factor,ty :";
	cin>>ty;
	for (int i=0;i<n;p++)
	{
		for(int j=0;j<3;q++)
		{
			transform[i][j]=0;
		}
	}
	
	transform[1][1]=1;
	transform[2][2]=1;
	transform[3][3]=1;
	transform[3][1]=tx;
	transform[3][2]=ty;
	
	multiply(n,transform[n][3],poly[n][3],result[n][3]);

}

void scale()
{

}

void rotate()
{
}


int main()
{
	
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	
	line(320,0,320,480);
	line(0,240,640,240);
	
	
	int ch,n;
	do
	{
		cleardevice();
		cout<<"\n\t--------MENU-------"<<endl;
		cout<<"\tEnter 1 for Translation\n\tEnter 2 for Scaling\n\tEnter 3 for Rotation\n\tEnter 4 for exit"<<endl;
		cout<<"\tEnter your Choice :";
		cin>>ch;
		
		
		int n;
		cout<<"\nEnter the No. of Vertices of the Polygon :";
		cin>>n;
		int poly[n][3];
		int result[n][3];
		int transform[n][3];
		get_coordinates(n,poly[n][3]);
	
		switch(ch)
		{
			case 1: cout<<"----------------------------------------------------------------------------------"<<endl;
					cout<<"TRANSLATION"<<endl;
					translate(n, transform[n][3],poly[][3]);
					setcolor(WHITE);
					draw(n,result[n][3]);
					break;
				
				
			case 2: cout<<"----------------------------------------------------------------------------------"<<endl;
					cout<<"SCALING"<<endl;
					break;
				
			case 3: cout<<"----------------------------------------------------------------------------------"<<endl;
					cout<<"ROTATION"<<endl;
					break;
				
			case 1: cout<<"----------------------------------------------------------------------------------"<<endl;
					cout<<"Exiting Input !!!"<<endl;
					break;
		
			default :cout<<"Wrong Input !!!"<<endl;
		}
	}while(ch!=4);
				
	getch();
	closegraph();
	return 0;
}
