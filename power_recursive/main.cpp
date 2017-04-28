#include <iostream>
using namespace std;

float power (int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
        if (n>0)
        {
            if (n%2==0)
            {
                return power (x,n/2)*power (x,n/2);
            }
            else
            if (n%2 != 0)
            {
                return x*power (x,n-1);
            }
        }
        else
            if (n<0)
                {
                    return 1/power (x,-1*n);
                }
    
    return 0;
}

int main ()
{
    int x,n;
    cout<<"enter a positive number\n";
    cin>> x;
    cout<<"enter a integer exponent\n";
    cin>> n;
    cout << power (x,n)<<endl;
    return 0;
}
