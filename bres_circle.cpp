#include<iostream>
#include<graphics.h> 
using namespace std;

class circle1
{
	float Xc,Yc,r;
	public:
	void get();
	void draw_circle();
};

void circle1::get()
{
	char c;
	cout<<"\nEnter radius: ";
	cin>>r;
	cout<<"\nEnter coordinates of circle: ";
	cin>>Xc>>c>>Yc;
}

void circle1::draw_circle()
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
		delay(400);
	}
	
}






int main()
{

	circle1 c;
	c.get();
  	int gd = DETECT,gm;
 	initgraph(&gd,&gm,NULL);
	c.draw_circle();
	delay(5000);
   	closegraph();


	return 0;
}






