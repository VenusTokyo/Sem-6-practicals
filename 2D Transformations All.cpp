
Computer Graphics Lab-7

Vaishnavi Jha
2018355

Write a program implementing 2D transformations.
Program:

#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>

#define pi 3.14285714

class transformations
{
double vertices[3][3];             //matrix contains vertices of the triangle
double t_matrix[3][3];             //transformation matrix
double result[3][3];

public:
transformations(){};

void get_vertices();
void display_triangle();
void display_triangle_result();

void multiplication();
void copyback();

void rotation(double angle,double m,double n);
void reflection(double m,double c);
void scaling(double a,double d);
void shearing(double b,double c);

};


void transformations::get_vertices()
{
int i=0;

for(i=0;i<3;i++)
     {
    cout<<"\nEnter vertex "<<i+1<<"...";
    cout<<"\nx1 : ";
    cin>>vertices[i][0];
    result[i][0]=vertices[i][0];

    cout<<"y1 : ";
    cin>>vertices[i][1];
    result[i][1]=vertices[i][1];

    vertices[i][2]=result[i][2]=1;
     }
}


void transformations::display_triangle()
{
int i=0;

for(i=0;i<2;i++)
     line(vertices[i][0],vertices[i][1],vertices[i+1][0],vertices[i+1][1]);
     line(vertices[i][0],vertices[i][1],vertices[0][0],vertices[0][1]);
}


void transformations::display_triangle_result()
{
int i=0;

for(i=0;i<2;i++)
     line(result[i][0],result[i][1],result[i+1][0],result[i+1][1]);
     line(result[i][0],result[i][1],result[0][0],result[0][1]);
}


void transformations::copyback()
{
int i=0,j=0;

for(i=0;i<3;i++)
for(j=0;j<3;j++)
result[i][j]=vertices[i][j];
}


void transformations::multiplication()
{
double r[3][3];
int i=0,j=0,k=0;

    for(i=0;i<3;i++)
     {
    for(j=0;j<3;j++)
         {
        r[i][j]=0;
        for(k=0;k<3;k++)
        r[i][j]+=result[i][k]*t_matrix[k][j];
         }
     }

for(i=0;i<3;i++)              //Copying back the result
for(j=0;j<3;j++)
result[i][j]=r[i][j];
}

//ROTATION:-

void transformations::rotation(double angle,double m,double n)
{
angle=((pi/180)*angle);

copyback();
cleardevice();

setcolor(RED);
display_triangle();
delay(20);
getch();

t_matrix[0][0]=1;                     //Matrix for translating the triangle to origin
t_matrix[0][1]=0;
t_matrix[0][2]=0;
t_matrix[1][0]=0;
t_matrix[1][1]=1;
t_matrix[1][2]=0;
t_matrix[2][0]=(m*(-1));
t_matrix[2][1]=(n*(-1));
t_matrix[2][2]=1;

    multiplication();

t_matrix[0][0]=cos(angle);             //Matrix to perform rotation about origin
t_matrix[0][1]=sin(angle);
t_matrix[1][0]=(sin(angle)*(-1));;
t_matrix[1][1]=cos(angle);
t_matrix[2][0]=0;
t_matrix[2][1]=0;

    multiplication();

t_matrix[0][0]=1;                      //Matrix to translate back to original centre of rotation
t_matrix[0][1]=0;
t_matrix[1][0]=0;
t_matrix[1][1]=1;
t_matrix[2][0]=m;
t_matrix[2][1]=n;

    multiplication();

setcolor(GREEN);
display_triangle_result();
delay(20);
getch();
}

//REFLECTION:-

void transformations::reflection(double m,double c)
{
double angle=atan(m);                //tan inverse(slope)=angle

copyback();
cleardevice();

double x1=0,y1=c,x2=400,y2=(m*x2)+c;
setcolor(YELLOW);
line(x1,y1,x2,y2);
delay(20);
getch();

setcolor(RED);
display_triangle();
delay(20);
getch();

t_matrix[0][0]=1;                     //translate (0,-c)
t_matrix[0][1]=0;
t_matrix[0][2]=0;
t_matrix[1][0]=0;
t_matrix[1][1]=1;
t_matrix[1][2]=0;
t_matrix[2][0]=0;
t_matrix[2][1]=(c*(-1));
t_matrix[2][2]=1;

    multiplication();

t_matrix[0][0]=cos(-1*angle);             //rotate the object about the x-axis by -angle
t_matrix[0][1]=sin(-1*angle);
t_matrix[1][0]=(sin(-1*angle)*(-1));;
t_matrix[1][1]=cos(-1*angle);
t_matrix[2][0]=0;
t_matrix[2][1]=0;

    multiplication();

t_matrix[0][0]=1;                      //reflection about x-axis
t_matrix[0][1]=0;
t_matrix[1][0]=0;
t_matrix[1][1]=-1;
t_matrix[2][0]=0;
t_matrix[2][1]=0;

    multiplication();

t_matrix[0][0]=cos(angle);             //rotate the object about the x-axis by -angle
t_matrix[0][1]=sin(angle);
t_matrix[1][0]=(sin(angle)*(-1));;
t_matrix[1][1]=cos(angle);
t_matrix[2][0]=0;
t_matrix[2][1]=0;

    multiplication();

t_matrix[0][0]=1;                       //translating back to original line of reflection
t_matrix[0][1]=0;
t_matrix[1][0]=0;
t_matrix[1][1]=1;
t_matrix[2][0]=0;
t_matrix[2][1]=c;

    multiplication();

setcolor(GREEN);
display_triangle_result();
delay(20);
getch();
}


//SCALING:-

void transformations::scaling(double a,double d)
{
copyback();
cleardevice();

setcolor(RED);
display_triangle();
delay(20);
getch();

t_matrix[0][0]=a;                     //Matrix for scaling the triangle
t_matrix[0][1]=0;
t_matrix[0][2]=0;
t_matrix[1][0]=0;
t_matrix[1][1]=d;
t_matrix[1][2]=0;
t_matrix[2][0]=0;
t_matrix[2][1]=0;
t_matrix[2][2]=1;

    multiplication();

setcolor(GREEN);
display_triangle_result();
delay(20);
getch();
}


//SHEARING:-

void transformations::shearing(double b,double c)
{
copyback();
cleardevice();

setcolor(RED);
display_triangle();
delay(20);
getch();

t_matrix[0][0]=1;                     //Matrix for shearing the triangle
t_matrix[0][1]=b;
t_matrix[0][2]=0;
t_matrix[1][0]=c;
t_matrix[1][1]=1;
t_matrix[1][2]=0;
t_matrix[2][0]=0;
t_matrix[2][1]=0;
t_matrix[2][2]=1;

    multiplication();

setcolor(GREEN);
display_triangle_result();
delay(20);
getch();
}


void main()
{
clrscr();
int gd=DETECT,gm,choice;
transformations t1;
char ch1,ch2;
double angle,m,n,slope,intercept,a,b,c,d;

do
    {
cout<<"\n\n\t   ........TWO DIMENSIONAL TRANSFORMATIONS........\n";
cout<<"\nEnter the details of a triangle(i.e. 2-D object).....";
       t1.get_vertices();

    do
      {
    initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
    cout<<"\n.......MENU.......";
    cout<<"\n1.Rotation.";
    cout<<"\n2.Reflection.";
    cout<<"\n3.Scaling.";
    cout<<"\n4.Shearing.";
    cout<<"\n..................";

    cout<<"\n\nEnter your choice :: ";
    cin>>choice;

    switch(choice)
          {
        case 1:cout<<"\n\nFOR ROTATION..........";
            cout<<"\nEnter the angle of rotation :: ";
            cin>>angle;

            cout<<"\nNow,enter the point about which you wanna perform rotation :: ";
            cout<<"\nx coordinate : ";
            cin>>m;
            cout<<"y coordinate : ";
            cin>>n;

            t1.rotation(angle,m,n);
            break;

        case 2:cout<<"\n\nFOR REFLECTION..........";
            cout<<"\nTo enter the line in slope-intercept form(i.e. y=mx+c)....";
            cout<<"\nEnter slope(m) : ";
            cin>>slope;
            cout<<"Then,enter y-intercept(c) : ";
            cin>>intercept;

            t1.reflection(slope,intercept);
            break;

        case 3:cout<<"\n\nFOR SCALING..........";
            cout<<"\nEnter the factor of scaling...";
            cout<<"\nAlong the x-axis : ";
            cin>>a;
            cout<<"And, along the y-axis : ";
            cin>>d;

            t1.scaling(a,d);
            break;

        case 4:cout<<"\n\nFOR SHEARING..........";
            cout<<"\nEnter the factor of shearing...";
            cout<<"\nAlong the x-axis : ";
            cin>>c;
            cout<<"And, along the y-axis : ";
            cin>>b;

            t1.shearing(b,c);
            break;

        default:cout<<"\n\n\t!!!INVALID CHOICE!!!";
            getch();
          }

    closegraph();

    cout<<"\nWanna try another tarnsformation(y/n)...";
    cin>>ch2;

    }while(ch2=='y');

cout<<"\n\nWant to try with a triangle of different dimensions(y/n)? ";
cin>>ch1;

}while(ch1=='y');
}
