# include <iostream>
#include <math.h>
using namespace std;

int main ()

{int array [11] = {1,3,5,12,15,63,76,78,88,90,91};
    
cout <<"enter number you want to look for\n";
    int target; int max; int min; int guess;
cin >> target;
    min = 0; max = 10;

while (max>=min){
    
    guess = round ( (min+max)/2);
    if (array [guess] == target)
    {
        cout<<"position in the array is "<<guess<< endl;
        break;
    }
    
    else if (array [guess] < target)
    
    {
        min = guess +1;
    }
    else {
        
        max = guess -1;
        }
        
        }
if (max<min) {
    cout<<"number is not there";
    cout<<endl;

}


return 0;}
