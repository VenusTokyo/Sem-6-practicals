#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
void circlePoints(int x,int y,int x_centre,int y_centre)
{
 putpixel(x+x_centre,y+y_centre,RED);
delay(100);
putpixel(-x+x_centre,y+y_centre,RED);
delay(100);
putpixel(x+x_centre,-y+y_centre,RED);
delay(100);
putpixel(-x+x_centre,-y+y_centre,RED);
delay(100);
putpixel(y+y_centre,x+x_centre,RED);
delay(100);
putpixel(-y+y_centre,x+x_centre,RED);
delay(100);
putpixel(y+y_centre,-x+x_centre,RED);
delay(100);
putpixel(-y+y_centre,-x+x_centre,RED);
delay(100);
}
void midPointCircle(int r,int x_centre,int y_centre)
{
 int x=0;
 int y=r;
 double d=3-2*r;
 while(y>x)
 {
  if(d<0)
   d=d+4*x+6.0;
  else
  {
  d=d+4*(x-y)+10.0;
  y=y-1;
  }
  x++;
 circlePoints(x,y,x_centre,y_centre);
}
return;
}

void main()
{
int i,gd=DETECT,gm;
int x,y,r;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
cout<<"Enter the centre coordinates:\n";
cout<<"x: ";
cin>>x;
cout<<"y: ";
cin>>y;
cout<<"Enter radius: ";
cin>>r;
setbkcolor(WHITE);
midPointCircle(r,x,y);
getch();

}

