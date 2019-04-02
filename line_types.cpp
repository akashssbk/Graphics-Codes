#include<iostream>
#include<cmath>
#include<graphics.h> 
using namespace std;

class l
{
	public:
	
	void dotted(float x1,float y1,float x2,float y2,int color);
	void dda(float x1,float y1,float x2,float y2,int color);
	void dashed(float x1,float y1,float x2,float y2,int color);
	void dotted_dashed(float x1,float y1,float x2,float y2,int color);
	void thick(float x1,float y1,float x2,float y2,int color);
};

void l::dotted(float x1,float y1,float x2,float y2,int color)
{
	float dx,dy,x,y,xinc,yinc;
	int steps;
	dy=y2-y1;
	dx=x2-x1;

	if(abs(dy)>abs(dx))
	steps=abs(dy);
	else
	steps=abs(dx);
	
	xinc=dx/steps;
	yinc=dy/steps;
	
	x=x1;
	y=y1;
	
	putpixel(x1,y1,color);
	while(steps>0)
	{
		for(int i=0;i<2;i++){
		x+=xinc;
		y+=yinc;
		putpixel(round(x),round(y),color);
		}
		x+=2*xinc;
		y+=2*yinc;
		
		steps-=4;
	}
}





void l::dda(float x1,float y1,float x2,float y2,int color)
{
	float dx,dy,x,y,xinc,yinc;
	int steps;
	dy=y2-y1;
	dx=x2-x1;

	if(abs(dy)>abs(dx))
	steps=abs(dy);
	else
	steps=abs(dx);
	
	xinc=dx/steps;
	yinc=dy/steps;
	
	x=x1;
	y=y1;
	
	putpixel(x1,y1,color);
	while(steps>0)
	{
		x+=xinc;
		y+=yinc;
		putpixel(round(x),round(y),color);
		steps-=1;
	}
}














void l::dashed(float x1,float y1,float x2,float y2,int color)
{
	float dx,dy,x,y,xinc,yinc;
	int steps;
	dy=y2-y1;
	dx=x2-x1;

	if(abs(dy)>abs(dx))
	steps=abs(dy);
	else
	steps=abs(dx);
	
	xinc=dx/steps;
	yinc=dy/steps;
	
	x=x1;
	y=y1;
	
	putpixel(x1,y1,color);
	while(steps)
	{
		for(int i=0;i<6;i++){
		x+=xinc;
		y+=yinc;
		putpixel(round(x),round(y),color);
		}
		
		x+=4*xinc;
		y+=4*yinc;
		
		steps-=10;
	}
}




void l::dotted_dashed(float x1,float y1,float x2,float y2,int color)
{
	float dx,dy,x,y,xinc,yinc;
	int steps;
	dy=y2-y1;
	dx=x2-x1;

	if(abs(dy)>abs(dx))
	steps=abs(dy);
	else
	steps=abs(dx);
	
	xinc=dx/steps;
	yinc=dy/steps;
	
	x=x1;
	y=y1;
	
	putpixel(x1,y1,color);
	while(steps>0)
	{
		for(int i=0;i<6;i++){
		x+=xinc;
		y+=yinc;
		putpixel(round(x),round(y),color);
		}
		
		x+=4*xinc;
		y+=4*yinc;
		
		for(int i=0;i<2;i++){
		x+=xinc;
		y+=yinc;
		putpixel(round(x),round(y),color);
		}		
		
		x+=4*xinc;
		y+=4*yinc;
		
		steps-=16;
	}
}


void l::thick(float x1,float y1,float x2,float y2,int color)
{


	float dx,dy,x,y,xinc,yinc;
	int steps;
	dy=y2-y1;
	dx=x2-x1;

	if(abs(dy)>abs(dx))
	steps=abs(dy);
	else
	steps=abs(dx);
	
	xinc=dx/steps;
	yinc=dy/steps;
	
	x=x1;
	y=y1;










	int width,w;
	cout<<"Enter width: ";
	cin>>width;
	
	int gd=DETECT,gm;	
	initgraph(&gd,&gm,NULL);
	
	
	w=((width-1)*sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1))))/(2*abs(x2-x1));
	
	
	float a[4],b[4];
	a[0]=x1;
	b[0]=y1-w;
	a[1]=x1;
	b[1]=y1+w;
	a[2]=x2;
	b[2]=y2-w;
	a[3]=x2;
	b[3]=y2+w;
	
	dda(a[0],b[0],a[1],b[1],color);
	dda(a[1],b[1],a[3],b[3],color);
	dda(a[2],b[2],a[3],b[3],color);
	dda(a[0],b[0],a[2],b[2],color);
	setcolor(color);
	
		x+=4*xinc;
		y+=4*yinc;
	floodfill(x,y,color);

}












int main()
{
	int op=1;
	l draw;
	
	int x1,y1,x2,y2;
	char ch;
	
	int gd=DETECT,gm;
	while(op)
	{
		cout<<"\nEnter starting point: ";
		cin>>x1>>ch>>y1;
		cout<<"\nEnter starting point: ";
		cin>>x2>>ch>>y2;
						
				
		cout<<"\nSelect your choice: ";
		cout<<"\n1)dotted line \n2)dashed line \n3)dotted dashed line \n4)thick\n";
		cin>>op;
		switch(op)
		{
			case 1: initgraph(&gd,&gm,NULL); draw.dotted(x1,y1,x2,y2,RED); delay(3000); break;
			case 2: initgraph(&gd,&gm,NULL); draw.dashed(x1,y1,x2,y2,RED); delay(3000); break;
			case 3: initgraph(&gd,&gm,NULL); draw.dotted_dashed(x1,y1,x2,y2,RED); delay(3000); break;
			case 4:  draw.thick(x1,y1,x2,y2,RED); delay(3000); break;
			case 5: op=0; break;
			default: cout<<"\nWrong choice!!";
		}
		closegraph();
	}


	return 0;
}
