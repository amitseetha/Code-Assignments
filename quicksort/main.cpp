#include <iostream>
using namespace std;

int i,k;
int partition (int mainarray[], int start, int end)
{
    
    int Pindex = start;
    //cout<<"start "<< start << "  end  "<< end;
//    for (i=start;i<=end;i++)
//    {
//        cout << mainarray [i];
//    }
    for (i=start;i<=end;i++)
    {
        if (mainarray [i]<=mainarray[end])
        {
            k=mainarray [i];
            mainarray [i] = mainarray [Pindex];
            mainarray [Pindex] = k;
            Pindex++;
        }
        
        
    }
    Pindex--;
    return Pindex;
}


int* quicksort (int mainarray[],int start,int end)
{
//    cout << "  start  "<< start << "  end  "<< end;
    
//    for (i=start;i<=end;i++)
//    {
//        cout << mainarray[i];
//    }
    if (start>=end)
    {
        return mainarray;
    }
    else
    {
       int Pindex = partition (mainarray,start,end);
        
        quicksort (mainarray,start,Pindex-1);
        quicksort (mainarray,Pindex,end);
    }
    return mainarray;

}

int main ()
{
    int i;
    int mainarray [13] = {12,55,42,1,-1,4545,333,277,22,567,34,22,9};
    quicksort (mainarray,0,12);
    cout <<"sorted array is: \n";
    
    for (i=0;i<13;i++)
    {
        cout << mainarray [i]<<endl;
    }
    return 0;
}
