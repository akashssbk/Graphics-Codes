//Vehicle locomotion program in c++: 
#include<graphics.h>
#include<iostream>


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

