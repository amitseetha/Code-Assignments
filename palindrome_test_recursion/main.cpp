#include <iostream>
using namespace std;

bool ispalindrome (string word)
{
    
    if (word.size() <=1)
    {
        return true;
    }
    else
    {
        if (word [0] == word [word.size()-1])
        {
            return ispalindrome (word.substr(1,(word.size()-2)));
        }
        else
        {
            return false;
        }
    }
}


int main ()
{
    string word;
    cout<< "enter word\n";
    cin>> word;
    if (ispalindrome(word) == true)
    {
        cout<< "true\n";
    }
    else
        cout <<"false\n";
    return 0;
}


