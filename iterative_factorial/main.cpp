#include <iostream>
using namespace std;

int main ()
{
    int i, n; long b=1;
    cout << "enter number \n";
    cin >> n;
    
    for (i=1;i<n;i++)
    {
        b = b*(i+1);
    }
    cout << b << endl;
    return 0;
}
