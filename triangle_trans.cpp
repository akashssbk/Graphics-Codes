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
	void translate();
	void scale();
	void rotate();
};


	void abc::translate()
	{
		double a,b,c,d,e,f;
		char jk;
		cout<<"\nEnter 3 points: ";
		cin>>a>>jk>>b;
		cin>>c>>jk>>d;
		cin>>e>>jk>>f;

		double p,q,r,s,t,u;	
	
		float tx,ty;
		cout<<"\nEnter tx: ";
		cin>>tx;
		cout<<"\nEnter ty: ";
		cin>>ty;
		
		
		p=a+tx;
		q=b+ty;
		r=c+tx;
		s=d+ty;
		t=e+tx;
		u=f+ty;
		
		  int gd = DETECT,gm;
 		initgraph(&gd,&gm,NULL);		
		dda(a,b,c,d,RED);
		dda(c,d,e,f,RED);
		dda(a,b,e,f,RED);
		
		dda(p,q,r,s,GREEN);
		dda(r,s,t,u,GREEN);
		dda(p,q,t,u,GREEN);
	}  


	void abc::scale()
	{
		double a,b,c,d,e,f;
		char jk;
		cout<<"\nEnter 3 points: ";
		cin>>a>>jk>>b;
		cin>>c>>jk>>d;
		cin>>e>>jk>>f;

		double p,q,r,s,t,u;		
	
		float sx,sy;
		cout<<"\nEnter sx: ";
		cin>>sx;
		cout<<"\nEnter sy: ";
		cin>>sy;
		
		
		p=a*sx;
		q=b*sy;
		r=c*sx;
		s=d*sy;
		t=e*sx;
		u=f*sy;
		  int gd = DETECT,gm;
 		initgraph(&gd,&gm,NULL);		
		dda(a,b,c,d,RED);
		dda(c,d,e,f,RED);
		dda(a,b,e,f,RED);
		
		dda(p,q,r,s,GREEN);
		dda(r,s,t,u,GREEN);
		dda(p,q,t,u,GREEN);
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



	void abc::rotate()
	{
		double a,b,c,d,e,f;
		char jk;
		cout<<"\nEnter 3 points: ";
		cin>>a>>jk>>b;
		cin>>c>>jk>>d;
		cin>>e>>jk>>f;


		double tv;
		cout<<"\nEnter angle";
		cin>>tv;
		double p=a,q=b,r,s,t,u;
		
		r=c*cos((tv*3.1428)/180.00)-d*sin((tv*3.1428)/180.00)-a*cos((tv*3.1428)/180.00)+b*sin((tv*3.1428)/180.00)+a;
		s=d*cos((tv*3.1428)/180.00)+c*sin((tv*3.1428)/180.00)-b*cos((tv*3.1428)/180.00)-a*sin((tv*3.1428)/180.00)+b;
		
		t=e*cos((tv*3.1428)/180.00)-f*sin((tv*3.1428)/180.00)-a*cos((tv*3.1428)/180.00)+b*sin((tv*3.1428)/180.00)+a;
		u=f*cos((tv*3.1428)/180.00)+e*sin((tv*3.1428)/180.00)-b*cos((tv*3.1428)/180.00)-a*sin((tv*3.1428)/180.00)+b;
		
		  int gd = DETECT,gm;
 		initgraph(&gd,&gm,NULL);	
		dda(a,b,c,d,RED);
		dda(c,d,e,f,RED);
		dda(a,b,e,f,RED);
		
		dda(p,q,r,s,GREEN);
		dda(r,s,t,u,GREEN);
		dda(p,q,t,u,GREEN);
	}  













int main()
{
    int a;
	float x1,y1,x2,y2;
	char ch;
	do{
		cout<<"\nEnter \n1)To Translate\n2)To Scale\n3)To Rotate";
		cin>>a;
 		abc draw;
 		switch(a)
 		{
 	   		case 1:draw.translate(); delay(2000); break;
 	   		case 2:draw.scale(); delay(2000); break;
			case 3:draw.rotate();
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
