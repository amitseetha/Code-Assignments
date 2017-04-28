#include <iostream>
using namespace std;

int i, j;

int* merge (int lowhalf[],int highhalf[],int mainarray[],int q, int size)
{
    int l=0,m=0,n=0;
    while (l<q and m< size-q)
    {
        if (lowhalf [l]<=highhalf[m])
        {
            mainarray [n] = lowhalf [l];
            l++;n++;
        }
        else
        {
            mainarray [n] = highhalf [m];
            m++;n++;
        }
    }
    while (l<q)
    {
        mainarray [n] = lowhalf [l];
        n++;l++;
    }
    while (m<size-q)
    {
        mainarray [n] = highhalf [m];
        m++;n++;
    }
    return mainarray;
}

int* mergesort (int mainarray[], int size)
{
    int q = size/2;
    int highhalf [size-q];
    int lowhalf [q];
    if (size == 1)
    {
        return mainarray;
    }
    else
    {
        for (int i=0;i<q;i++)
    {
        lowhalf [i] = mainarray [i];
    }
        mergesort (lowhalf,q);
        
        for (i=0;i<size-q;i++)
    {
        highhalf [i] = mainarray [i+q];
    }
        mergesort (highhalf,size-q);
    }
    
    merge (lowhalf,highhalf,mainarray,q,size);

    return mainarray;
}


int main ()
{
    int i;
    int mainarray [9] = {123,2354,34,2,1,2454,234,656,21};
    mergesort (mainarray,9);
    
    for (i=0;i<9;i++)
    {
        cout<<mainarray[i]<<endl;
    }
    return 0;
}

/*array
base case - array of size 1 which is already sorted, to return the array itself
if base case not true:
break into two halves and apply the same fucntion to each part.
merge function: make sorted array from constituent arrays

step1: if base case is true then return the same array
if size = 0, return mainarray
step2: if base case is not true:
break the array into two nearly equal parts:
q = round (p+ size/2);
copy array from p to q into an array lowhalf
for i = p to i = q into lowhalf
apply mergesort on lowhalf
for i = q+1 to i = p plus size -1 copy to highhalf
apply mergesort to highhalf
merge highhalf and lowhalf with sorting
while i < (size of lowkey) and j < (size of highkey)
if lowkey[i] <= highkey [j] then mainarray [k] = lowkey [i]; i++, k++;
else mainarray [k] = highhalf [j]; j++, k++;
while i <= (size of lowhalf)
mainarray [k] = lowhalf [i];i++, k++
while j<= (size of highhalf)
mainarray [k] = highhalf [j], k++, j++
*/

