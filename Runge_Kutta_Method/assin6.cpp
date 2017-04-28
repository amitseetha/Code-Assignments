#include<iostream>
using namespace std;
float mod(float x){ if(x>=0){return x;}else return (-x); }//defining modulus function
int main()
{float g3o,g3n,g2o=0,g2n,g3o0,g3o1,g1o=0,g1n,k1,k2,k3,k4,h=0.5,g2n1,g2n2;int i=0;//defining parameters
g3o=g3o0=0.1;cout<<"SHOOTING METHOD\n\ntaking g3o = "<<g3o<<"\nthe values of g1,g2,g3 are as tabulated:\n";

do{k1=-g1o*g3o/2;//runge kutta for g3n
k2=-((g1o+h*g2o*0.5)*(g3o-h*0.25*g1o*g3o))*0.5;k3=k2;
k4=-((g1o+h*g2o)*(g3o-h*g1o*g3o*0.5))*0.5;
g3n=g3o+h*(k1+2*k2+2*k3+k4)/6;

k1=g3o;//runge kutta for g2n
k2=g3o-h*0.25*g1o*g3o;k3=k2;
k4=g3o-h*0.5*g1o*g3o;
g2n=g2o+h*(k1+2*k2+2*k3+k4)/6;

k1=g2o;//runge kutta for g1n
k2=g2o+h*0.5*g3o;k3=k2;
k4=g2o+h*g3o;
g1n=g1o+h*(k1+2*k2+2*k3+k4)/6;i++;

cout<<"g1n = "<<g1n<<"\t\tg2n = "<<g2n<<"\t\tg3n = "<<g3n<<"\n";
g1o=g1n;g2o=g2n;g3o=g3n;}while(i<20);cout<<"\n\n";
g2n1=g2n;i=0;

g3o=g3o1=0.3;g1o=g2o=0;cout<<"\ntaking g3o = "<<g3o<<"\nthe values of g1,g2,g3 are as tabulated:\n";

do{k1=-g1o*g3o/2;//repeating runge kutta method for socond initial guess
k2=-((g1o+h*g2o*0.5)*(g3o-h*0.25*g1o*g3o))*0.5;k3=k2;
k4=-((g1o+h*g2o)*(g3o-h*g1o*g3o*0.5))*0.5;
g3n=g3o+h*(k1+2*k2+2*k3+k4)/6;

k1=g3o;
k2=g3o-h*0.25*g1o*g3o;k3=k2;
k4=g3o-h*0.5*g1o*g3o;
g2n=g2o+h*(k1+2*k2+2*k3+k4)/6;

k1=g2o;
k2=g2o+h*0.5*g3o;k3=k2;
k4=g2o+h*g3o;
g1n=g1o+h*(k1+2*k2+2*k3+k4)/6;i++;

cout<<"g1n = "<<g1n<<"\t\tg2n = "<<g2n<<"\t\tg3n = "<<g3n<<"\n";
g1o=g1n;g2o=g2n;g3o=g3n;}while(i<20);cout<<"\n\n";
g2n2=g2n;i=0;g1o=g2o=0;

do{g3o=g3o0+(g3o0-g3o1)*(g2n1-1)/(g2n2-g2n1);g3o0=g3o1;g3o1=g3o;//secant method to correct g3o
cout<<"\ninterpolating correct g3o = "<<g3o<<"\nthe final values of g1,g2,g3 are as tabulated:\n";
do{k1=-g1o*g3o/2;//repeating iterations for corrected g3o and so on till g2 tends to 1 at infinite neta
k2=-((g1o+h*g2o*0.5)*(g3o-h*0.25*g1o*g3o))*0.5;k3=k2;
k4=-((g1o+h*g2o)*(g3o-h*g1o*g3o*0.5))*0.5;
g3n=g3o+h*(k1+2*k2+2*k3+k4)/6;

k1=g3o;
k2=g3o-h*0.25*g1o*g3o;k3=k2;
k4=g3o-h*0.5*g1o*g3o;
g2n=g2o+h*(k1+2*k2+2*k3+k4)/6;

k1=g2o;
k2=g2o+h*0.5*g3o;k3=k2;
k4=g2o+h*g3o;
g1n=g1o+h*(k1+2*k2+2*k3+k4)/6;i++;

cout<<"g1n = "<<g1n<<"\t\tg2n = "<<g2n<<"\t\tg3n = "<<g3n<<"\n";
g1o=g1n;g2o=g2n;g3o=g3n;} while(i<20);
i=0;g1o=g2o=0;
g2n1=g2n2;g2n2=g2n;}while (mod(g2n2-1)>.00001);  


cin>>i;
return 0;
} 

