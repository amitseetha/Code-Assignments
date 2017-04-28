//simple gaussian elimination with data input from a text file
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

int main()
{int n,i,j,p;float M;//defining parameters
    cout << "no of variables?\n";
    cin>> n;
    float matrix [n][n+1];
    
    ifstream myfile ("example.txt"); // data input from text file
    if (myfile.is_open()){ while(! myfile.eof()){for(i=1;i<=n;i++){for(j=1;j<=(n+1);j++){myfile >>matrix[i][j];}} myfile.close(); }  }
    else cout << "Unable to open file";
    
    cout<<"\nthe augmented coefficient matrix is \n";
    for(i=1;i<=n;i++){for(j=1;j<=(n+1);j++){cout<< matrix[i][j]<<"\t";}cout<<"\n";}//display of augmented matrix as entered
    
    for(i=1;i<=(n-1);i++){for(j=i+1;j<=n;j++){M = (matrix [j][i])/(matrix [i][i]);p=i;for(i=i;i<=(n+1);i++){matrix [j][i] = matrix [j][i] -(M*(matrix[p][i]));}i=p;}}//fwd elimination
    //display of augmented matrix after fwd elimination, also correcting error introduced due to rounding off by computer
    cout<<"\nthe augmented coefficient matrix after fwd elimination is \n";
    for(i=1;i<=n;i++){for(j=1;j<=(n+1);j++){if (matrix[i][j]<1.00000e-005 && matrix[i][j]>-1.00000e-005) matrix[i][j] = 0;cout<< matrix[i][j]<<"\t\t";}cout<<"\n";}
    
    //denying the possibilty of no or infinite solutions, also of the cases when pivoting is required
    if(matrix[n][n] == 0) {cout<<"no unique solution, STOP\n type any integer to exit";cin>> n;exit (1);}
    
    float solution [n];//back subtitution and display of solution vector
    solution[n]=(matrix[n][n+1])/(matrix[n][n]);cout<<"solution "<<n<<"= "<<solution[n]<<"\n";
    for(i=(n-1);i>=1;i--){float s=0;for(j=(i+1);j<=n;j++){s=s+ (matrix[i][j]*solution[j]);}solution[i]=((matrix[i][n+1]- s)/matrix[i][i]);cout<<"solution "<<i<<"= "<<solution[i]<<"\n";}
    cin>>n;
    return 0;
}
//The solutions of Q2 obtained as output are:
//X1= 1.91813
//X2= 1.96491
//X3= -0.988304
//X4= -3.19298
//X5= -1.1345
