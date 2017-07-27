#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void Isolted(vector<int> adj[],int n)
{
    int out[n],count = 0;
    for(int i=0; i<n; i++)
    {
        out[i] = adj[i].size();
    }

    int in[n];
    for(int i=0; i<n; i++)
    {
        in[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            in[adj[i][j]]++;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(in[i] == 0 && out[i] == 0)
        {
            printf("%d is an isolated node\n",i+1);
            count++;
        }
    }
    printf("The number of isolated nodes are %d",count);

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
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    Isolted(adj,n);


    return 0;
}

