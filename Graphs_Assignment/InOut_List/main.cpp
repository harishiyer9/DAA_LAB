#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void OutDegree(vector<int> adj[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"The out degree of vertex "<<i+1<<" is "<<adj[i].size()<<"\n";
    }
}
void InDegree(vector<int> adj[],int n)
{
    int count[n];
    for(int i=0;i<n;i++)
    {
        count[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            count[adj[i][j]]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<"The in degree of vertex "<<i+1<<" is "<<count[i]<<"\n";
    }
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
    InDegree(adj,n);
    OutDegree(adj,n);


    return 0;
}

