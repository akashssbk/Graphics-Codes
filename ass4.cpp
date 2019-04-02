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
	void bres(float x1,float y1,float x2,float y2,int color);
	void draw_diagram(float Xc,float Yc,float r);
	void draw_circle(float Xc,float Yc,float r,int color);

};

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



	void abc::draw_circle(float Xc,float Yc,float r,int color)
		{
			int d,x,y;
			d=3-2*r;
			x=0;
			y=r;
	
			putpixel(Xc+x,Yc+y,color);
			putpixel(Xc+y,Yc+x,color);
			putpixel(Xc+y,Yc-x,color);
			putpixel(Xc+x,Yc-y,color);
			putpixel(Xc-x,Yc-y,color);
			putpixel(Xc-y,Yc-x,color);
			putpixel(Xc-y,Yc+x,color);
			putpixel(Xc-x,Yc+y,color);
	
			while(x<=y)
			{
				x=x+1;
				if(d<0)
				{
					d=d+(4*x)+6;
				}
				else
				{
					y=y-1;
					d=d+(4*(x-y))+10;
				}
				putpixel(Xc+x,Yc+y,color);
				putpixel(Xc+y,Yc+x,color);
				putpixel(Xc+y,Yc-x,color);
				putpixel(Xc+x,Yc-y,color);
				putpixel(Xc-x,Yc-y,color);
				putpixel(Xc-y,Yc-x,color);
				putpixel(Xc-y,Yc+x,color);
				putpixel(Xc-x,Yc+y,color);
			}
	
		}



















	void abc::draw_diagram(float Xc,float Yc,float r)          //accepting two points
	{
		float a[3],b[3];

/*************************************** OUTER CIRCLE ***************************************/		

		draw_circle(Xc,Yc,r,RED);
		
/*************************************** TRIANGLE ***************************************/		
		a[0]=Xc;
		b[0]=Yc-r;
		a[1]=(Xc-(0.8660254f*r));
		b[1]=Yc+(r/2);
		a[2]=(Xc+(0.8660254f*r));
		b[2]=Yc+(r/2);

		bres(a[0],b[0],a[1],b[1],GREEN);
		delay(200);
		bres(a[1],b[1],a[2],b[2],GREEN);
		delay(200);
		bres(a[2],b[2],a[0],b[0],GREEN);
		delay(200);		
		
/*************************************** INNER CIRCLE ***************************************/				
		draw_circle(Xc,Yc,r/2.00f,YELLOW);
	}









	
	
	


int main()
{
    int a;
	float x,y,r;
	char ch;
	do{
	cout<<"\nEnter centre point: ";
	cin>>x>>ch>>y;
	if(x>640) {x=640;}
	if(y>480) {y=480;}
	cout<<"\nEnter outer radius: ";
	cin>>r;
	if(r>640) {r=640;}
	if(r>480) {r=480;}
	
	if(r>y || r>x)
	{
		cout<<"\nWrong points!!\nPLEASE ENTER DIAGONAL POINTS ONLY!!";
	}
	else
	{
		int gd = DETECT,gm;
 		initgraph(&gd,&gm,NULL);
 		abc draw;
		draw.draw_diagram(x,y,r);
		delay(3000);
		closegraph();
	}
 
   	cout<<"\nDo you want to continue??[y/n]: ";
   	cin>>ch;
   	}while(ch=='y' || ch=='Y');
   	return 0;
}
