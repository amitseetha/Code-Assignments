//breadth-first search as learnt at https://www.khanacademy.org/computing/computer-science/algorithms/breadth-first-search/a/the-breadth-first-search-algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int i,j, num_vertices=8;

vector<vector<int>> dobfs (vector<vector<int>> grapharray, int num_vertices)
{
    vector<vector<int>> bfsinfo;
    
    for(int i = 0; i< num_vertices; i++)//filling bfsinfo with null values
    {
        vector <int> row;
        for(int j= 0; j <2 ; j++)
        {
            row.push_back(-1);
            row.push_back(0);
        }
        bfsinfo.push_back(row);
    }
    
    queue <int> queue1;// defining queue and a set for visited vertices and source variable
    set<int> donesofar;
    int current = 3;
    
    while(true)
    {
            for (j=0;j<num_vertices;j++)
            {
                if (grapharray [current][j] == 1)
                {
                    if(j == current)
                    {
                        continue;
                    }
                    
                    set<int>::iterator op = donesofar.find(j); // searching the set donesofar for vertex
                    if(op == donesofar.end())//if vertex is not already there, then put it in queue
                    {
                        queue1.push(j);
                        bfsinfo [j][0]=current;
                        bfsinfo[j][1] = bfsinfo[current][1]+1;//in vertex j push current in first place and push in second place 1 plus second place of 'current' vertex
                    }
                }
            }
    
    
        donesofar.insert(current);
        if(!queue1.empty())
        {
            current = queue1.front();
            queue1.pop();//queue1 is used to change value of 'current'
        }
        else
        {
            break;
        }
    }
    return bfsinfo;
}


int main ()
{
    
    vector<vector<int>> grapharray;
    cout << "enter vertices as in adjacency matrix \n";// 1 means connected vertices, 0 means no link
    
    for(int i = 0; i< num_vertices; i++)//filling bfsinfo with null values
    {
        vector <int> row;
        for(int j= 0; j <num_vertices ; j++)
        {
            cout<<"enter ["<<i<<"] ["<<j<<"] \n";
            int input ;
            cin >>input;
            row.push_back(input);
        }
        grapharray.push_back(row);
    }
    
    cout <<" The Adjacency matrix you entered is (please check):"<<endl;
    for (i=0;i<=7;i++)//display and check grapharray
    {
        for (j=0;j<num_vertices;j++)
        {
            cout << grapharray[i][j]<<"\t";
        }
        cout<<endl;
    }

    vector<vector<int>> bfsinfo = dobfs(grapharray, 8);
    cout<<"The matrix below lists BFS outputs for all vertices; (-1,0) indicates source or disconnected vertices"<<endl;
    for (i=0;i<num_vertices;i++)
    {
        for (j=0;j<2;j++)
        {
            cout << bfsinfo[i][j]<< "\t";
        }
        cout<<endl;
    }
    cout<<"* each element [x,y] means you are y steps away from source and you have to jump to vertex x next to reach by shortest path"<<endl;
    return 0;
}
