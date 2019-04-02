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
	void translate(float x1,float y1,float x2,float y2);
	void scale(float x1,float y1,float x2,float y2);
	void rotate(float x1,float y1,float x2,float y2);
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



	void abc::translate(float x1,float y1,float x2,float y2)
	{
		float tx,ty;
		cout<<"\nEnter tx: ";
		cin>>tx;
		cout<<"\nEnter ty: ";
		cin>>ty;
		
		float p,q,r,s;
		
		p=x1+tx;
		q=y1+ty;
		r=x2+tx;
		s=y2+ty;
		  int gd = DETECT,gm;
 		initgraph(&gd,&gm,NULL);		
		dda(x1,y1,x2,y2,RED);
		dda(p,q,r,s,GREEN);
	}  


	void abc::scale(float x1,float y1,float x2,float y2)
	{
		float sx,sy;
		cout<<"\nEnter sx: ";
		cin>>sx;
		cout<<"\nEnter sy: ";
		cin>>sy;
		
		float p,q,r,s;
		
		p=x1*sx;
		q=y1*sy;
		r=x2*sx;
		s=y2*sy;
		  int gd = DETECT,gm;
 		initgraph(&gd,&gm,NULL);		
		dda(x1,y1,x2,y2,RED);
		dda(p,q,r,s,GREEN);
	}  



	void abc::rotate(float x1,float y1,float x2,float y2)
	{
		double t;
		cout<<"\nEnter angle";
		cin>>t;
		double p,q;
		
		p=x2*cos((t*3.1428)/180.00)-y2*sin((t*3.1428)/180.00)-x1*cos((t*3.1428)/180.00)+y1*sin((t*3.1428)/180.00)+x1;
		q=y2*cos((t*3.1428)/180.00)+x2*sin((t*3.1428)/180.00)-y1*cos((t*3.1428)/180.00)-x1*sin((t*3.1428)/180.00)+y1;
		  int gd = DETECT,gm;
 		initgraph(&gd,&gm,NULL);	
		dda(x1,y1,x2,y2,RED);
		dda(x1,y1,p,q,GREEN);
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
		cout<<"\nEnter \n1)To Translate\n2)To Scale\n3)To Rotate";
		cin>>a;
 		abc draw;
 		switch(a)
 		{
 	   		case 1:draw.translate(x1,y1,x2,y2); delay(2000); break;
 	   		case 2:draw.scale(x1,y1,x2,y2); delay(2000); break;
			case 3:draw.rotate(x1,y1,x2,y2);
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
