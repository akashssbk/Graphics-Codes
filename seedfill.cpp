#include <iostream>
#include <cmath>
#include<graphics.h> 
using namespace std;



class abc
{
	public:
	void dda(float x1,float y1,float x2,float y2,int color);
	void flood_fill(float x,float y,int bcolor,int fcolor);
	void boundary_fill(float x,float y,int bcolor,int fcolor);
	void draw_rectangle(float x1,float y1,float x2,float y2,int color);
};

	void abc::dda(float x1,float y1,float x2,float y2,int color)          //accepting two points
	{
		float dx,dy,x,y;
		int step;                                               //Variable to store number of times the for loop is to be executed
		dx=x2-x1;
		dy=y2-y1;
		if(abs(dx)>abs(dy))
			step=abs(dx);
		else
			step=abs(dy);
			
		float xin,yin;                                          //Variables to store value by which X and Y coordinates will incriment
		xin=dx/step;
		yin=dy/step;
		x=x1;
		y=y1;
		putpixel(x,y,color);
		for(int i=0;i<step;i++)
		{
			x+=xin;
			y+=yin;
			round(x);                                          //Rounding of the values
			round(y);
			putpixel(x,y,color);
		}
	
	
	}





	void abc::draw_rectangle(float x1,float y1,float x2,float y2,int color)          //accepting two points
	{
/*************************************** RECTANGLE ***************************************/		
		dda(x1,y1,x2,y1,color);
		delay(200);
		dda(x2,y1,x2,y2,color);
		delay(200);
		dda(x2,y2,x1,y2,color);
		delay(200);
		dda(x1,y2,x1,y1,color);
		delay(200);
	}


void abc::flood_fill(float x,float y,int bcolor,int fcolor)
{
	if(getpixel(x,y)==bcolor)
	{
		putpixel(x,y,fcolor);
		delay(1);
		flood_fill(x+1,y,bcolor,fcolor);
		flood_fill(x,y+1,bcolor,fcolor);
		flood_fill(x-1,y,bcolor,fcolor);
		flood_fill(x,y-1,bcolor,fcolor);
	}
}


void abc::boundary_fill(float x,float y,int bcolor,int fcolor)
{
	if(getpixel(x,y)!=bcolor && getpixel(x,y)!=fcolor)
	{
		putpixel(x,y,fcolor);
		delay(1);		
		boundary_fill(x+1,y,bcolor,fcolor);
		boundary_fill(x,y+1,bcolor,fcolor);
		boundary_fill(x-1,y,bcolor,fcolor);
		boundary_fill(x,y-1,bcolor,fcolor);
	}
}





int main()
{
    int a,b;
	float x1,y1,x2,y2;
	char ch;
	do{
		cout<<"\nEnter type of polygon \n1)rectangle: ";
		cin>>a;
		if(a==1)
		{
			cout<<"\nEnter first diagonal point: ";
			cin>>x1>>ch>>y1;
			if(x1>640) {x1=640;}
			if(y1>480) {y1=480;}
			cout<<"\nEnter second diagonal point: ";
			cin>>x2>>ch>>y2;
			if(x2>640) {x2=640;}
			if(y2>480) {y2=480;}
			
			
			
			if(x1==x2 || y1==y2)
			{	
				cout<<"\nWrong points!!\nPLEASE ENTER DIAGONAL POINTS ONLY!!";
			}
			else
			{
			
				cout<<"\nEnter \n1)flood fill \n2)boundary fill\n";
				cin>>b;
				
				int gd = DETECT,gm;
 				initgraph(&gd,&gm,NULL);
 				abc draw;
				draw.draw_rectangle(x1,y1,x2,y2,YELLOW);
				if(b==1)
					draw.flood_fill((x1+x2)/2,(y1+y2)/2,BLACK,RED);
				else
					draw.boundary_fill((x1+x2)/2,(y1+y2)/2,YELLOW,RED);
				delay(3000);
				closegraph();
			}
 		}
 		else
 			cout<<"\nWrong type..!!";
   	cout<<"\nDo you want to continue??[y/n]: ";
   	cin>>ch;
   	}while(ch=='y' || ch=='Y');
   	return 0;
}
