#include <iostream>
using namespace std;

int main ()
{
    int array [11] = {2300,322, 322, 34,23,5656,34343,22266,14,68754,-100};
    int i,j,b;
    
    for (i=1;i<=10;i++)
    {
        b = array [i];
        for (j=i-1;j>=0;j--)
        {
            if (array [j]>= b)
            {
                array [j+1] = array [j];
                array [j] = b;
            }
            
        }
    }
    
    for (i=0;i<=10;i++)
    {
        cout << array [i] << endl;
    }
    return 0;
}
