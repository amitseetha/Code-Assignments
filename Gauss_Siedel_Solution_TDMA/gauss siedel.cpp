//gauss siedel soln for tdma
#include<iostream>
using namespace std;
int main()
{int n,i,j,p,m,r;float N,M,z,k,s1,s2;//defining parameters
cout << "GAUSS SIEDEL Soln for TDMA \n \n please enter delta zeta and N \n";
cin>> z>>N;
n=(1/z)-.99;//doubt ask
cout<<"n is "<<n<<"\n";
float c[n],d[n];//defining parameters//doubt ask
k=(2+ N*N*z*z);

float matrix [n][n+1];
for(i=2;i<=n-1;i++){matrix[i][i]=k;matrix[i][i+1]=matrix[i][i-1]=-1;}//definining matrix content
for(i=1;i<=n;i++){for(j=i+2;j<=n;j++){matrix[i][j]=0;}}
for(i=n;i>=1;i--){for(j=i-2;j>=1;j--){matrix[i][j]=0;}}
matrix[1][1]=k;matrix[n][n]=k-1;matrix[1][2]=matrix[n][n-1]=-1;
for(i=1;i<=n;i++){if(i==1)matrix[i][n+1]=1; else matrix[i][n+1]=0;}
cout<<"\nthe tridiagonal coefficient matrix is \n";
for(i=1;i<=n;i++){for(j=1;j<=n+1;j++){cout<< matrix[i][j]<<"\t";}cout<<"\n";}//display of tri diagonal matrix 

cout << "please enter m(no of iterations for gauss siedel method)  \n";
cin>> m;
float T[m][n];
cout<<"enter initial guess values for gauss siedel method\n";
for(i=1;i<=n;i++){cout<<"T"<<i<<" = ";cin>> T [1][i];}//gauss siedel method
for(i=1;i<=n;i++){c[i]=matrix[i][n+1];}
for(i=2;i<=m;i++){for(j=1;j<=n;j++){s1=0;for(r=1;r<=j-1;r++){s1=s1+T[i][r]*matrix[j][r];}s2=0;for(r=j+1;r<=n;r++){s2=s2+T[i-1][r]*matrix[j][r];}T[i][j]=(c[j]-s1-s2)/matrix[j][j];}}
cout<<"\nThe Gauss Siedel results as per successive iterations are tabulated below \n\n";
for(i=1;i<=m;i++){for(j=1;j<=n;j++){cout<< T[i][j]<<"\t";}cout<<"\n";}//display of results

cin>>n; 
return 0;}

