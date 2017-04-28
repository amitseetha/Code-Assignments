//TDMA
#include<iostream>
using namespace std;
int main()
{int n,i,j,p;float N,M,z,k,a[n],b[n],c[n],d[n],A[n+1],Q[n+2],C[n];//defining parameters;
cout << "TDMA \n\n please enter delta zeta and N \n";
cin>> z>>N;n=(1/z)-.99;
k=(2+ N*N*z*z);
float matrix [n][n+1];//defining tridiagonal matrix
for(i=2;i<=n-1;i++){matrix[i][i]=k;matrix[i][i+1]=matrix[i][i-1]=-1;}
for(i=1;i<=n;i++){for(j=i+2;j<=n;j++){matrix[i][j]=0;}}
for(i=n;i>=1;i--){for(j=i-2;j>=1;j--){matrix[i][j]=0;}}
matrix[1][1]=k;matrix[n][n]=k-1;matrix[1][2]=matrix[n][n-1]=-1;
for(i=1;i<=n;i++){if(i==1)matrix[i][n+1]=1; else matrix[i][n+1]=0;}
  
cout<<"\nthe tridiagonal augmented coefficient matrix is \n";
for(i=1;i<=n;i++){for(j=1;j<=n+1;j++){cout<< matrix[i][j]<<"\t";}cout<<"\n";}//display of augmented td matrix as entered
b[1]=0;for(j=2;j<=n;j++){b[j]=-matrix[j][j-1];}//calculating coefficients and results
for(i=1;i<n;i++){d[i]=matrix[i][i];}d[n]=k-1;
for(i=1;i<=n-1;i++){a[i]=-matrix[i][i+1];}a[n]=0;
for(i=1;i<=n;i++){c[i]=matrix[i][n+1];}
A[0]=0;for(i=1;i<=n;i++){A[i]=a[i]/(d[i]-b[i]*A[i-1]);}
C[0]=0;for(i=1;i<=n;i++){C[i]=(b[i]*C[i-1]+c[i])/(d[i]-b[i]*A[i-1]);}
Q[n+1]=Q[n]=C[n]/(1-A[n]);for(i=n;i>=1;i--){Q[i]=A[i]*Q[i+1]+C[i];}

cout<<"\n\n b is \n";//display of results
for(i=1;i<=n;i++){cout<<"b"<<i<<" = "<<b[i]<<"\n";}
cout<<"\n\n d is \n";
for(i=1;i<=n;i++){cout<<"d"<<i<<" = "<<d[i]<<"\n";}
cout<<"\n\n a is \n";
for(i=1;i<=n;i++){cout<<"a"<<i<<" = "<<a[i]<<"\n";}
cout<<"\n\n c is \n";
for(i=1;i<=n;i++){cout<<"c"<<i<<" = "<<c[i]<<"\n";}
cout<<"\n\n A is \n";
for(i=1;i<=n;i++){cout<<"A"<<i<<" = "<<A[i]<<"\n";}
cout<<"\n\n C is \n";
for(i=1;i<=n;i++){cout<<"C"<<i<<" = "<<C[i]<<"\n";}
cout<<"\n\n Q is \n";
for(i=1;i<=n;i++){cout<<"Q"<<i<<" = "<<Q[i]<<"\n";}

cin>>n; 
return 0;}

