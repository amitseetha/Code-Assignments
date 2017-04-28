#include <iostream>
using namespace std;

int main ()
{
    int array [11] = {2341,2341,65464,473,23439,5646,2343, 23,345,234523,343};
    int i,j,k,b;
    
   
    for (j=0;j<=10;j++)
    {
        b = array [j];
        for (i=j;i<=10;i++)
        {
            if (b >= array [i])
            {
                b = array [i];
            }
        }
        for (i=j;i<=10;i++)
        {
            if (array [i] == b)
            {
                k = array [j];
                array [j] = b;
                array [i] = k;
            }
        }
    
    }
  
    
    for (i=0;i<=10;i++)
    {
     cout<< array [i]<<endl;
    }

return 0;
    
}


