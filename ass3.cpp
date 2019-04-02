#include <iostream>
#include <cmath>
#include<graphics.h> 
using namespace std;

/*
    class for declaring functions for DDA & Bresenham Line drawng algorithm
*/

class abc
{
	public:
	void dda(float x1,float y1,float x2,float y2);
	void bres(float x1,float y1,float x2,float y2,int color);
	void draw_diagram(float x1,float y1,float x2,float y2);

};

	void abc::dda(float x1,float y1,float x2,float y2)          //accepting two points
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
		putpixel(x,y,YELLOW);
		for(int i=0;i<step;i++)
		{
			x+=xin;
			y+=yin;
			round(x);                                          //Rounding of the values
			round(y);
			putpixel(x,y,YELLOW);
		}
	
	
	}
	
	
	void abc::bres(float x1,float y1,float x2,float y2,int color)
	{
		float dx,dy,x=x1,y=y1,pk;										//Required variables
		int step;
 		/* Calculating steps */

		dx=x2-x1;
		dy=y2-y1;
		if(abs(dx)>abs(dy))
			step=abs(dx);
		else
			step=abs(dy);
		int m;                                                          //Slope variable
		if(dx!=0.00)
		m=abs(dy/dx);
		else
		m=2;															//Avoid divide by Zero
/*
    For m<1 X will always be incremented/decremented at each step and Y will increment/decrement as per the value of decision parameter(Pk)
*/
		if(m<1)
		{
		
			putpixel(x,y,color);                                        //put starting pixel on screen
			pk=(2*abs(dy))-abs(dx);                                     //Calculate initial decision parameter
			
			for(int i=0;i<step;i++)
			{
			/*
			     If X2 is greater than X1 X-Coordinates should be incremented 
			     Else If X2 is less than X1 X-Coordinates should be decremented
			*/
				if(dx>0.00)
				x=x+1;
				else
				x=x-1;
				if(pk<0)
					pk+=(2*abs(dy));                                     //Absolute values must be considred so as to handle all cases
				else
				{
			/*
			     If Y2 is greater than Y1 Y-Coordinates should be incremented 
			     Else If Y2 is less than Y1 Y-Coordinates should be decremented
			*/
					if(dy>0.00)
					y=y+1;
					else
					y=y-1;
					pk+=(2*abs(dy))-(2*abs(dx));                        //Absolute values must be considred so as to handle all cases
				}
				putpixel(x,y,color);
			}
			
		}
/*
    For m>1 Y will always be incremented/decremented at each step and X will increment/decrement as per the value of decision parameter(Pk)
*/		
		else
		{
			putpixel(x,y,color);
			pk=(2*abs(dx))-abs(dy);
			for(int i=0;i<step;i++)
			{
			/*
			     If Y2 is greater than Y1 Y-Coordinates should be incremented 
			     Else If Y2 is less than Y1 Y-Coordinates should be decremented
			*/
				if(dy>0.00)
					y=y+1;
				else
					y=y-1;
				if(pk<0)
				{
					pk+=(2*abs(dx));                                   //Absolute values must be considred so as to handle all cases
				}
				else
				{
			/*
			     If X2 is greater than X1 X-Coordinates should be incremented 
			     Else If X2 is less than X1 X-Coordinates should be decremented
			*/
					if(dx>0.00)
				x=x+1;
				else
				x=x-1;
					pk+=(2*abs(dx))-(2*abs(dy));                      //Absolute values must be considred so as to handle all cases
				}
				putpixel(x,y,color);
			}
		}
	
	}



	void abc::draw_diagram(float x1,float y1,float x2,float y2)          //accepting two points
	{
		float a[4],b[4],c[4],d[4];

/*************************************** OUTER RECTANGLE ***************************************/		
		bres(x1,y1,x2,y1,RED);
		delay(200);
		bres(x2,y1,x2,y2,RED);
		delay(200);
		bres(x2,y2,x1,y2,RED);
		delay(200);
		bres(x1,y2,x1,y1,RED);
		delay(200);
		
		a[0]=(x1+x2)/2;
		b[0]=y1;
		a[1]=x2;
		b[1]=(y1+y2)/2;
		a[2]=(x1+x2)/2;
		b[2]=y2;
		a[3]=x1;
		b[3]=(y1+y2)/2;
		
/*************************************** INNER DIAMOND ***************************************/		
		bres(a[0],b[0],a[1],b[1],GREEN);
		delay(200);
		bres(a[1],b[1],a[2],b[2],GREEN);
		delay(200);
		bres(a[2],b[2],a[3],b[3],GREEN);
		delay(200);
		bres(a[3],b[3],a[0],b[0],GREEN);
		delay(200);
		
		
		c[0]=(a[0]+a[3])/2;
		d[0]=(b[0]+b[3])/2;
		c[1]=(a[0]+a[1])/2;
		d[1]=(b[0]+b[1])/2;
		c[2]=(a[1]+a[2])/2;
		d[2]=(b[1]+b[2])/2;
		c[3]=(a[2]+a[3])/2;
		d[3]=(b[2]+b[3])/2;

/*************************************** INNER RECTANGLE ***************************************/				
		bres(c[0],d[0],c[1],d[1],BLUE);
		delay(200);
		bres(c[1],d[1],c[2],d[2],BLUE);
		delay(200);
		bres(c[2],d[2],c[3],d[3],BLUE);
		delay(200);
		bres(c[3],d[3],c[0],d[0],BLUE);
		delay(200);
	}









	
	
	


int main()
{
    int a;
	float x1,y1,x2,y2;
	char ch;
	do{
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
		int gd = DETECT,gm;
 		initgraph(&gd,&gm,NULL);
 		abc draw;
		draw.draw_diagram(x1,y1,x2,y2);
		delay(3000);
		closegraph();
	}
 
   	cout<<"\nDo you want to continue??[y/n]: ";
   	cin>>ch;
   	}while(ch=='y' || ch=='Y');
   	return 0;
}
