#include <iostream>
#include <cmath>
#include<graphics.h> 
using namespace std;

#define pi 3.1428f

/*
    class for declaring functions for DDA & Bresenham Line drawng algorithm
*/

class abc
{
	public:
	void dda(float x1,float y1,float x2,float y2,int color);
	void xshear(float x1,float y1,float x2,float y2);
	void yshear(float x1,float y1,float x2,float y2);
};


	void abc::yshear(float x1,float y1,float x2,float y2)
	{
		float shy;
		cout<<"\nEnter shy: ";
		cin>>shy;

		double p,q,r,s;
		
		p=y1+shy*x1;
		q=y2+shy*x1;
		r=y1+shy*x2;
		s=y2+shy*x2;
		
		  int gd = DETECT,gm;
 		initgraph(&gd,&gm,NULL);		
		dda(x1,y1,x1,y2,RED);
		dda(x1,y2,x2,y2,RED);
		dda(x2,y2,x2,y1,RED);
		dda(x2,y1,x1,y1,RED);
				
		dda(x1,p,x1,q,GREEN);
		dda(x1,q,x2,s,GREEN);
		dda(x2,s,x2,r,GREEN);
		dda(x2,r,x1,p,GREEN);
	}  


	void abc::xshear(float x1,float y1,float x2,float y2)
	{
		float shx;
		cout<<"\nEnter shx: ";
		cin>>shx;

		double p,q,r,s;
		
		p=x1+shx*y1;
		q=x2+shx*y1;
		r=x1+shx*y2;
		s=x2+shx*y2;
		
		  int gd = DETECT,gm;
 		initgraph(&gd,&gm,NULL);		
		dda(x1,y1,x1,y2,RED);
		dda(x1,y2,x2,y2,RED);
		dda(x2,y2,x2,y1,RED);
		dda(x2,y1,x1,y1,RED);
				

		dda(p,y1,q,y2,GREEN);
		dda(q,y2,s,y2,GREEN);
		dda(s,y2,r,y1,GREEN);
		dda(r,y1,p,y1,GREEN);

	}  




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

int main()
{
    int a;
	float x1,y1,x2,y2;
	char ch;
	do{
		cout<<"\nEnter first point: ";
		cin>>x1>>ch>>y1;
		if(x1>640) {x1=640;}
		if(y1>480) {y1=480;}
		cout<<"\nEnter second point: ";
		cin>>x2>>ch>>y2;
		if(x2>640) {x2=640;}
		if(y2>480) {y2=480;}	
	
	
		cout<<"\nEnter \n1)Xshear\n2)Yshear\n";
		cin>>a;
 		abc draw;
 		switch(a)
 		{
 	   		case 1:draw.xshear(x1,y1,x2,y2); delay(4000); break;
 	   		case 2:draw.yshear(x1,y1,x2,y2); delay(4000); break;
        		   delay(2000);
				   break;
 	    default	:cout<<"\nWrong option";
 		}
 
   	closegraph();
   	cout<<"\nDo you want to continue??[y/n]: ";
   	cin>>ch;
   	}while(ch=='y' || ch=='Y');
   	return 0;
}
