//Vehicle locomotion program in c++: 
#include<graphics.h>
#include<iostream>


	void dda(float x1,float y1,float x2,float y2)
	{
		float dx,dy,x,y;
		int step;
		dx=x2-x1;
		dy=y2-y1;
		if(abs(dx)>abs(dy))
			step=abs(dx);
		else
			step=abs(dy);
			
		float xin,yin;
		xin=dx/step;
		yin=dy/step;
		x=x1;
		y=y1;
		putpixel(x,y,YELLOW);
		for(int i=0;i<step;i++)
		{
			x+=xin;
			y+=yin;
			round(x);
			round(y);
			putpixel(x,y,YELLOW);	
		}
	
	
	}



void draw_circle(float Xc,float Yc,float r)
{
	int d,x,y;
	d=3-2*r;
	x=0;
	y=r;
	
	putpixel(Xc+x,Yc+y,5);
	putpixel(Xc+y,Yc+x,5);
	putpixel(Xc+y,Yc-x,5);
	putpixel(Xc+x,Yc-y,5);
	putpixel(Xc-x,Yc-y,5);
	putpixel(Xc-y,Yc-x,5);
	putpixel(Xc-y,Yc+x,5);
	putpixel(Xc-x,Yc+y,5);
	
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
		putpixel(Xc+x,Yc+y,5);
		putpixel(Xc+y,Yc+x,5);
		putpixel(Xc+y,Yc-x,5);
		putpixel(Xc+x,Yc-y,5);
		putpixel(Xc-x,Yc-y,5);
		putpixel(Xc-y,Yc-x,5);
		putpixel(Xc-y,Yc+x,5);
		putpixel(Xc-x,Yc+y,5);
	}
	
}







int main()
{
int gdriver=DETECT,gmode,j=0;
initgraph(&gdriver,&gmode,NULL);
for(float i=0;i<420.00;++i)
{
line(0,245,650,245);
line(0+i,200,210+i,200);
line(50+i,200,70+i,170);
line(70+i,170,140+i,170);
line(140+i,170,160+i,200);
line(85+i,170,85+i,200);
line(125+i,170,125+i,200);
line(0+i,200,0+i,230);
line(210+i,200,210+i,230);
line(0+i,230,50+i,230);
circle(65+i,230,15);
line(80+i,230,130+i,230);
circle(145+i,230,15);
line(210+i,230,160+i,230);


delay(50);
cleardevice();
}
closegraph();
return 0;
}

