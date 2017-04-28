#include <iostream>
using namespace std;

int main ()
{
    string word;
    cout << "enter word \n";
    cin >> word;
    long n = word.length (), c = 0, i, j;
    
    for (i=0,j= n-1;i<=j;i++,j--)
    {
        if (word [i]==word [j])
        {c=1;}
        else
        {
            c=0;
            break;
        }
    }
    if (c==0) {cout<<"not a palindrome \n";
    }
    else
    {
        cout <<"is a palindrome \n";
    }
    return 0;
}
