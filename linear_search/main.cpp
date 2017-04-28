#include <iostream>
using namespace std;

int main ()

{
    int array [11] = {1,3,5,12,15,63,76,78,88,90,91};
    cout <<"enter number you want to look for\n";
    int target, i;
    cin >> target;
    
    for (i=0;i<=10;i++)
    {
        if (array [i] == target)
        {
            cout << "position in array is " << i << endl;
        }
    }
    cout << "number is not there\n";
    
    
    return 0;
}
