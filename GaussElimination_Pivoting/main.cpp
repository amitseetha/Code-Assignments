//gaussian elimination with pivoting and scaling (direct data input )
#include<iostream>
#include<cstdlib>
using namespace std;

float mod(float x){ if(x>=0){return x;}else return (-x); }//defining absolute value function

int main()
{int n,i,j,p;float M,q,max=0;//defining parameters
    cout << "no of variables?\n";
    cin>> n;
    float matrix [n][n+1],maxi[n],scali[n][n+1];
    
    //user entry of augmented coefficients
    for(i=1;i<=n;i++){for(j=1;j<=(n+1);j++){cout<<"enter coefficient "<<j<<" of row "<<i<<"  for augmented matrix  ";cin>> matrix [i][j];}}
    
    cout<<"\nthe augmented coefficient matrix is \n";
    for(i=1;i<=n;i++){maxi[i]=0;}//determining scale factors
    for(i=1;i<=n;i++){for(j=1;j<=n;j++){(maxi[i]>=matrix[i][j]) ? maxi[i]=maxi[i] : maxi[i] = matrix[i][j];}}
    for(i=1;i<=n;i++){for(j=1;j<=(n+1);j++){cout<< matrix[i][j]<<"\t";scali[i][j]=matrix[i][j]/maxi[i];}cout<<"\n";}//display of augmented matrix as entered
    
    //fwd elimination with scaling(and pivoting)
    for(i=1;i<=(n-1);i++){for(j=i;j<=n;j++){(max>=mod(scali[j][i]))? max=max:max = mod(scali[j][i]);if(max==mod(scali[j][i]))p=j;}
        for(j=1;j<=(n+1);j++){q=matrix[i][j];matrix[i][j]=matrix[p][j];matrix[p][j]=q;}
        for(j=(i+1);j<=n;j++){M = (matrix [j][i])/(matrix [i][i]);p=i;for(i=i;i<=(n+1);i++){matrix [j][i] = matrix [j][i] -(M*(matrix[p][i]));}i=p;
            M = (scali [j][i])/(scali [i][i]);p=i;for(i=i;i<=(n+1);i++){scali [j][i] = scali [j][i] -(M*(scali[p][i]));}i=p;}}
    cout<<"\nthe augmented coefficient matrix after fwd elimination is \n";
    
    //display of augmented matrix after fwd elimination, also correcting error introduced due to rounding off by computer
    for(i=1;i<=n;i++){for(j=1;j<=(n+1);j++){if (matrix[i][j]<1.00000e-005 && matrix[i][j]>-1.00000e-005) matrix[i][j] = 0;cout<< matrix[i][j]<<"\t\t";}cout<<"\n";}
    
    //denying the possibilty of no or infinite solutions
    if(matrix[n][n] == 0) {cout<<"no unique solution, STOP\n type any integer to exit";cin>> n;exit (1);}
    
    
    float solution [n];//back subtitution and display of solution vector
    solution[n]=(matrix[n][n+1])/(matrix[n][n]);cout<<"solution "<<n<<"= "<<solution[n]<<"\n";
    for(i=(n-1);i>=1;i--){float s=0;for(j=(i+1);j<=n;j++){s=s+ (matrix[i][j]*solution[j]);}solution[i]=((matrix[i][n+1]- s)/matrix[i][i]);cout<<"solution "<<i<<"= "<<solution[i]<<"\n";}
    
    cin>>n; 
    return 0;
}
//The answers to 2nd problem obtained as output are
//X1= 0.176825
//X2= 0.0126927
//X3=  -0.020654
//X4= -1.18261
