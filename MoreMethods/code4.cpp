//code 4
#include<iostream>
#include <math.h>
using namespace std;
float f(float x){return (pow(2.71828182,-x)-x);}
float fdash(float x){return (-pow(2.71828182,-x)-1);}
float mod(float x){ if(x>=0){return x;}else return (-x); }
int main ()
{int c;float e,x0=0,x1=1,x2;
cout<<"Please enter:\n1 -->  for BISECTION METHOD\n2 -->  for FALSE POSITION METHOD\n3 -->  for NEWTON RAPHSON METHOD\n4 -->  for SECANT METHOD\n";
cin>>c;
switch(c)
{case 1:{cout<<"BISECTION METHOD\n\nThe respective roots and true error as per successive iterations are as tabulated:\n\n";
do {x2=(x0+x1)/2;e=mod((x2-.56714329)/.56714329);cout<<"x = "<<x2<<"\t\t\t\t"<<"error = "<<e<<"\n";if((f(x2)*f(x1))<0){x0=x1;x1=x2;}else x1=x2;}while (e>.0000001);}break;
case 2:{cout<<"FALSE POSITION METHOD\n\nThe respective roots and true error as per successive iterations are as tabulated:\n\n";
do {x2=(x0-f(x0)*((x1-x0)/(f(x1)-f(x0))));e=mod((x2-.56714329)/.56714329);cout<<"x = "<<x2<<"\t\t\t\t"<<"error = "<<e<<"\n";if((f(x2)*f(x1))<0){x0=x1;x1=x2;}else x1=x2;}while (e>.0000001);}break;
case 3:{x1=0;cout<<"NEWTON RAPHSON METHOD\n\nThe respective roots and true error as per successive iterations are as tabulated:\n\n";
do {x2=x1-(f(x1)/fdash(x1));e=mod((x2-.56714329)/.56714329);cout<<"x = "<<x2<<"\t\t\t\t"<<"error = "<<e<<"\n";x1=x2;}while (e>.0000001);}break;
case 4:{cout<<"SECANT METHOD\n\nThe respective roots and true error as per successive iterations are as tabulated:\n\n";
do {x2=(x0-f(x0)*((x1-x0)/(f(x1)-f(x0))));e=mod((x2-.56714329)/.56714329);cout<<"x = "<<x2<<"\t\t\t\t"<<"error = "<<e<<"\n";x0=x1;x1=x2;}while (e>.0000001);}break;
default: cout<<"please dont try silly gimmicks";}
         
cin>>x2;
return 0;}
