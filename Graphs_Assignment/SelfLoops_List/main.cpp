#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>

using namespace std;

void SelfLoops(vector<int> adj[],int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            if(adj[i][j] == i)
            {
                count++;
            }
        }
    }
     printf("The number of self loops in the graphs are %d",count);
}


int main()
{
    int n;
    ifstream in;
    in.open("input.txt");
    in>>n;
    int **a = new int*[n];
    for(int i=0; i<n; i++)
    {
        a[i] = new int[n];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            in>>a[i][j];
        }
    }
    in.close();
    vector<int> adj[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    SelfLoops(adj,n);


    return 0;
}

