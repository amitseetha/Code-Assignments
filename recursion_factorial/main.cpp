# include <iostream>
using namespace std;

int n;
int factorial (int x)
{
    if (x==0)
        return 1;
    else
        return x*factorial (x-1);
}

int main ()
{
    cout << "enter number\n";
    cin >> n;
    cout << factorial (n) <<"\n";
}
