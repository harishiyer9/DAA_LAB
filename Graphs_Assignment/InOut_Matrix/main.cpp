#include<iostream>
#include<fstream>


using namespace std;

void OutDeg(int **a,int n)
{
    int count[n];
    for(int i=0; i<n; i++)
    {
        count[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            count[i] += a[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<"The out degree of vetex "<<i<<" is : "<<count[i]<<"\n";
    }
}

void InDeg(int **a,int n)
{
    int count[n];
    for(int i=0; i<n; i++)
    {
        count[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            count[i] += a[j][i];
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<"The in degree of vertex "<<i<<" is : "<<count[i]<<"\n";
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
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<a[i][j];
        }
        cout<<"\n";
    }
    OutDeg(a,n);
    InDeg(a,n);



    return 0;
}
