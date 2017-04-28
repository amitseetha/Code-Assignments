#include <iostream>
using namespace std;

int hanoi (int n, int n1, int n3, int n2)
{
    if (n>0)
    {
        hanoi (n-1,n1,n2,n3);
        cout << "move disk " <<n<< " from tower " << n1 << " to " << n3<< endl;
        hanoi (n-1,n2,n3,n1);
    }
    else
        if (n==0)
        {
            return 0;
        }
    else
        cout << "no of disks can't be negative \n";
    return 0;
}

int main ()
{
    int n;
    cout << "enter number of disks\n";
    cin >>n;
    hanoi (n,1,3,2);
    return 0;
}
