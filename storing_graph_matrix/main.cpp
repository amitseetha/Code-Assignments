#include <iostream>
using namespace std;

int main ()
{
    int i=0,j=0;
    int adjmtx [5][6];
    for (i=0;i<=4;i++)
    {
        for (j=0;j<=5;j++)
        {
            cout <<" enter adjmtx ["<<i<<"]["<<j<<"]\n";
            cin>> adjmtx [i][j];
        }
    }
    for (i=0;i<=4;i++)
    {
        for (j=0;j<=5;j++)
        {
            cout<< adjmtx [i][j]<<"\t";
        }
        cout<< endl;
    }
    return 0;
}
