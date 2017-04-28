//ADI + TDMA
#include<iostream>
using namespace std;
float mod(float x){ if(x>=0){return x;}else return (-x); }//modulus function
int main()
{float x,p,k=0;int r=1,s=1,i,j,n;//defining parameters
    cout<<"ASSIGNMENT 7\n\ntaking dt = 1 sec\nplease enter dx = dy =...\n";
cin>>x;p=(.5/x)-1;cout<<"\nInitially assumed temperature field :\n\nT1 :\n";
n=(int)p;
float T1[n+2][n+2],T2[n+2][n+2],matrix[n][n+1],a[n],b[n],c[n],d[n],A[n+1],Q[n+2],C[n+1];
for(i=0;i<=n+1;i++){for(j=0;j<=n+1;j++){T1[i][j]=T2[i][j]=0;}}//formulating initial temp matrices
for(i=0;i<n+2;i++){T1[i][n+1]=T1[n+1][i]=T2[i][n+1]=T2[n+1][i]=100/(n+1)*i;}
p=2.03125;
for(i=0;i<n+2;i++){for(j=0;j<n+2;j++){cout<< T1[i][j]<<"\t";}cout<<"\n";}
cout<<"\nT2 :\n";
for(i=0;i<n+2;i++){for(j=0;j<n+2;j++){cout<< T2[i][j]<<"\t";}cout<<"\n";}

do{for(i=1;i<=n-2;i++){matrix[i][i]=p;matrix[i][i+1]=matrix[i][i-1]=-1;}
for(i=0;i<n;i++){for(j=i+2;j<n;j++){matrix[i][j]=0;}}
for(i=n-1;i>=0;i--){for(j=i-2;j>=0;j--){matrix[i][j]=0;}}
matrix[0][0]=p;matrix[n-1][n-1]=p;matrix[0][1]=matrix[n-1][n-2]=-1;k++;
cout<<"\n\nThe temperature profile at time = "<< k-.5<<" seconds is :\n";

do{for(i=0;i<n;i++){if(i==0)matrix[i][n]=T2[r-1][s]+(p-4)*T2[r][s]+T2[r+1][s]+T1[r][0]; else matrix[i][n]=T2[r-1][s+1]+(p-4)*T2[r][s+1]+T2[r+1][s+1];}matrix[n-1][n]=T2[r-1][s+2]+(p-4)*T2[r][s+2]+T2[r+1][s+2]+T1[r][n+1];
b[0]=0;for(j=1;j<n;j++){b[j]=-matrix[j][j-1];}//calculating coefficients and results by TDMA method
for(i=0;i<n;i++){d[i]=matrix[i][i];}
for(i=0;i<n-1;i++){a[i]=-matrix[i][i+1];}a[n-1]=0;
for(i=0;i<n;i++){c[i]=matrix[i][n];}
A[0]=0;for(i=1;i<=n;i++){A[i]=a[i-1]/(d[i-1]-b[i-1]*A[i-1]);}
C[0]=0;for(i=1;i<=n;i++){C[i]=(b[i-1]*C[i-1]+c[i-1])/(d[i-1]-b[i-1]*A[i-1]);}
Q[n]=0;for(i=n-1;i>=0;i--){Q[i]=A[i+1]*Q[i+1]+C[i+1];}

for(i=0;i<n;i++){T1[r][i+1]=Q[i];}r++;}while(r<n+1);r=1;//updating T1 matrix
    
    for(i=0;i<n+2;i++){for(j=0;j<n+2;j++){cout<< T1[i][j]<<"\t";}cout<<"\n";}//T1 matrix output
      
    
    do{for(i=0;i<n;i++){if(i==0)matrix[i][n]=T1[r][s-1]+(p-4)*T1[r][s]+T1[r][s+1]+T2[0][s]; else matrix[i][n]=T1[r+1][s-1]+(p-4)*T1[r+1][s]+T1[r+1][s+1];}matrix[n-1][n]=T1[r+2][s-1]+(p-4)*T1[r+2][s]+T1[r+2][s+1]+T2[n+1][s];

b[0]=0;for(j=1;j<n;j++){b[j]=-matrix[j][j-1];}//calculating coefficients and results by TDMA method
for(i=0;i<n;i++){d[i]=matrix[i][i];}
for(i=0;i<n-1;i++){a[i]=-matrix[i][i+1];}a[n-1]=0;
for(i=0;i<n;i++){c[i]=matrix[i][n];}
A[0]=0;for(i=1;i<=n;i++){A[i]=a[i-1]/(d[i-1]-b[i-1]*A[i-1]);}
C[0]=0;for(i=1;i<=n;i++){C[i]=(b[i-1]*C[i-1]+c[i-1])/(d[i-1]-b[i-1]*A[i-1]);}
Q[n]=0;for(i=n-1;i>=0;i--){Q[i]=A[i+1]*Q[i+1]+C[i+1];}


for(i=0;i<n;i++){T2[i+1][s]=Q[i];}s++;}while(s<n+1);s=1;//updating T2 matrix
    cout<<"\n\nThe temperature profile at time = "<< k<<" seconds is :\n";
    for(i=0;i<n+2;i++){for(j=0;j<n+2;j++){cout<< T2[i][j]<<"\t";}cout<<"\n";}//T2 matrix output
}while((mod(T2[1][1]-T1[1][1])>.0001));
cout<<"\n...this is the final steady state temperature profile ";
        
cin>>n; 
return 0;}

