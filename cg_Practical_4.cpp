//2-D Transformations - Translation, Scaling and Rotation 

#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

void display(int n,float c[][3])
{
	float maxx,maxy;
	int i;
	maxx=getmaxx();
	maxy=getmaxy();
	maxx=maxx/2;
	maxy=maxy/2;
	i=0;
	while(i<n-1)
	{
	line(maxx+c[i][0],maxy-c[i][1],maxx+c[i+1][0],maxy-c[i+1][1]);
	i++;	
	}
	i=n-1;
	line(maxx+c[i][0],maxy-c[i][1],maxx+c[0][0],maxy-c[0][1]);
	setcolor(GREEN);
	line(0,maxy,maxx*2,maxy);	
	line(maxx,0,maxx,maxy*2);
	setcolor(WHITE);
}	
void multi(int n ,float b[][3],float c[][3], float a[][3])
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			a[i][j]=0;
		}	
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				a[i][j]=a[i][j]+(c[i][k] * b[k][j]);			
			}
		}	
	}
	
}
void translation(int n, float c[][3], float tx, float ty)
{
	float b[10][3],a[10][3];
	int i=0,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][j]=0;
		}	
	}
	b[0][0]=1;
	b[1][1]=1;
	b[2][2]=1;
	b[2][0]=tx;
	b[2][1]=ty;
	
	multi(n,b,c,a);
	setcolor(RED);
	display(n,a);
	getch();
		
}

void scaling(int n, float c[][3], float sx, float sy)
{
	float b[10][3],a[10][3];
	int i=0,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][j]=0;
		}	
	}
	b[0][0]=sx;
	b[1][1]=sy;
	b[2][2]=1;
	
	multi(n,b,c,a);
	setcolor(RED);
	display(n,a);
	getch();
	
}
void rotation(int n, float c[][3], float ra)
{
	float b[10][3],a[10][3],xp,yp;
	xp=c[0][0];
	yp=c[0][1];
	int i=0,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][j]=0;
		}	
	}
	b[0][0]=b[1][1]=cos(ra*3.14/180);
	b[0][1]=sin(ra*3.14/180);
	b[1][0]=-sin(ra*3.14/180);
	b[2][0]=(-xp*cos(ra*3.14/180))+(yp*cos(ra*3.14/180))+xp;
	b[2][1]=(-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
	b[2][2]=1;
	
	multi(n,b,c,a);
	setcolor(RED);
	display(n,a);
	getch();
	
		
}

int main()
{
	int i,j,k,n,ch;
	char chr;
	int gd,gm;
	gd=DETECT;
	float c[10][3],tx,ty,sx,sy,ra;
	initgraph(&gd,&gm,NULL);
	
	int random;
	cin>>random;
	cout<<"---------------------------------------------------------------"<<endl;
	
	cout<<"\nEnter the Number of Vertices of the Polygon :";
	cin>>n;
	for(i=0;i<n;i++)
	{	
		cout<<"Enter the "<<i+1<<" vertex (x,y):";
		cin>>c[i][0]>>c[i][1];
		c[i][2]=1;
	}
	do
	{
		cout<<"----------------------------------------------------------------------"<<endl;
		cout<<"\n\t\t\t* * * MENU * * *"<<endl;
		cout<<"\tEnter 1 for Translation\n\tEnter 2 for Scaling\n\tEnter 3 for Rotation\n\tEnter 4 for exit"<<endl;
		cout<<"\tEnter your Choice :";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"----------------------------------------------------------------------------------"<<endl;
					cout<<"\t\tTRANSLATION"<<endl;
					cout<<"\n\tEnter translation factor for x & y axis :\t";
					cin>>tx>>ty;
					cleardevice();
					setcolor(BLUE);
					display(n,c);
					translation(n,c,tx,ty);
					getch();
					break;
					
			case 2: cout<<"----------------------------------------------------------------------------------"<<endl;
					cout<<"SCALING"<<endl;
					cout<<"\n\tEnter scaling factor for x & y axis :";
					cin>>sx>>sy;
					cleardevice();
					setcolor(BLUE);
					display(n,c);
					scaling(n,c,sx,sy);
					getch();
					break;
					
			case 3: cout<<"----------------------------------------------------------------------------------"<<endl;
					cout<<"ROTATION"<<endl;
					cout<<"\n\tEnter the angle of rotation:\t";
					cin>>ra;
					cleardevice();
					setcolor(BLUE);
					display(n,c);
					rotation(n,c,ra);
					getch();
					break;
			case 4: cout<<"----------------------------------------------------------------------------------"<<endl;
					cout<<"Exiting !!!"<<endl;
					exit(0);
					break;
					
			default:cout<<"\n\tInvalid Choice !!"<<endl;
					break;
		}
		//cout<<"Do you want to continue :"<<endl;
		//cin>>chr;
	}while(ch<5);
	getch();
	closegraph();
	return 0;
	}




