#include<iostream>
#include<fstream>


using namespace std;

void SelfLoop(int **a,int n)
{
    int count = 0;

    for(int i=0; i<n; i++)
    {
        if(a[i][i] == 1)
        {
            printf("Vertex %d is having a self loop\n",i+1);
            count++;
        }
    }

    cout<<"The number of self loops are "<<count<<"\n";

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
    SelfLoop(a,n);

    return 0;
}
