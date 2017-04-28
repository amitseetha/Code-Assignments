#include<iostream>
#include<math.h>
using namespace std;
float mod(float x){ if(x>=0){return x;}else return (-x); }
int main()
{
    float Xn[3],Xo[3],Fo[3],Jo[3][3],B[3],error[3];int n,i,j,p,q=0;float M;n=3;
    Xo[0]=Xo[1]=Xo[2]=0;
    do {Fo[0]=6*Xo[0]-cos(Xo[1]*Xo[2])-1;
    Fo[1]=9*Xo[1]+pow((Xo[0]*Xo[0]+ sin(Xo[2])+1.06),0.5) + 0.9;
    Fo[2]=3*exp(-(Xo[0]*Xo[1]))+60*Xo[2] + 28.416;
    Jo[0][0]=6;
    Jo[0][1]=Xo[2]*sin(Xo[1]*Xo[2]);
    Jo[0][2]=Xo[1]*sin(Xo[1]*Xo[2]);
    Jo[1][0]=Xo[0]/pow((Xo[0]*Xo[0]+sin(Xo[2])+1.06),0.5);
    Jo[1][1]=9;
    Jo[1][2]=cos(Xo[2])/(2*pow((Xo[0]*Xo[0]+sin(Xo[2])+1.06),0.5));
    Jo[2][0]=-3*Xo[1]*exp(-Xo[0]*Xo[1]);
    Jo[2][1]=-3*Xo[0]*exp(-Xo[0]*Xo[1]);
    Jo[2][2]=60;
    for(i=0;i<3;i++){B[i]=Jo[i][0]*Xo[0]+Jo[i][1]*Xo[1]+Jo[i][2]*Xo[2]-Fo[i];}
    q++;
    
float matrix [n][n+1];
for(i=0;i<n;i++){for(j=0;j<n;j++){matrix [i][j]=Jo[i][j];}}//user entry of augmented coefficients
for(j=0;j<n;j++){matrix[j][n]=B[j];}
cout<<"\nIteration no "<<q<<"\n\nAfter converting to linear system,the augmented coefficient matrix is \n\n";
for(i=0;i<n;i++){for(j=0;j<(n+1);j++){cout<< matrix[i][j]<<"\t";}cout<<"\n";}//display of augmented matrix as entered

for(i=0;i<(n-1);i++){for(j=i+1;j<n;j++){M = (matrix [j][i])/(matrix [i][i]);p=i;for(i=i;i<(n+1);i++){matrix [j][i] = matrix [j][i] -(M*(matrix[p][i]));}i=p;}}//fwd elimination
for(i=0;i<n;i++){for(j=0;j<(n+1);j++){if (matrix[i][j]<1.00000e-005 && matrix[i][j]>-1.00000e-005) matrix[i][j] = 0;}}

//denying the possibilty of no or infinite solutions, also of the cases when pivoting is required
if(matrix[n-1][n-1] == 0) {cout<<"no unique solution, STOP\n type any integer to exit";cin>> n;exit (1);}
float solution [n];//back subtitution and display of solution vector
solution[n-1]=(matrix[n-1][n])/(matrix[n-1][n-1]);cout<<"\nsolutions are:\nX "<<n<<"= "<<solution[n-1]<<"\n";   
for(i=(n-2);i>=0;i--){float s=0;for(j=(i+1);j<=n-1;j++){s=s+ (matrix[i][j]*solution[j]);}solution[i]=((matrix[i][n]- s)/matrix[i][i]);cout<<"X "<<i+1<<"= "<<solution[i]<<"\n";}
for(i=0;i<n;i++){Xn[i]=solution[i];}cout<<"\n";

for(i=0;i<3;i++){error[i]=Xn[i]-Xo[i];cout<<"error in X"<<i+1<<" = "<<error[i]<<"\n";Xo[i]=Xn[i];}}while((mod(error[1])>.00001)||mod((error[0])>.00001)||(mod(error[2])>.00001));
cin>>n;
return 0;    
    }
