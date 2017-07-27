#include <iostream>
#include <fstream>

using namespace std;

void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

void CountingSort(int a[],int b[],int length,int k)
{
    int c[k+1];
    for(int i=0;i<=k;i++)
    {
        c[i] = 0;
    }
    for(int i=0;i<length;i++)
    {
        c[a[i]]++;
    }
    for(int i=1;i<=k;i++)
    {
        c[i]= c[i]+c[i-1];
    }

    for(int i=length-1;i>=0;i--)
    {
        b[c[a[i]]-1] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
}


int main()
{
    ifstream in;
    in.open("input.txt");
    int length,k;
    in >> length;
    int *a = new int[length];
    int *b = new int[length];
    in >> k;
    for(int i=0;i<length;i++)
    {
        in >> a[i];
    }
    in.close();
    CountingSort(a,b,length,k);
    ofstream out;
    out.open("output.txt");
    for(int i=0;i<length;i++)
    {
        out << b[i] <<"\n";
    }
    out.close();

    return 0;
}
