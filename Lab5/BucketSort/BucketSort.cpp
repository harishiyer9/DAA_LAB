#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>

using namespace std;

void BucketSort(float a[],int length)
{
    vector<float> b[length];
    for(int i=0; i<length; i++)
    {
        int index = length*a[i];
        b[index].push_back(a[i]);
    }
    for(int i=0; i<length; i++)
    {
        sort(b[i].begin(),b[i].end());
    }
    int k=0;
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<b[i].size();j++)
        {
            a[k++] = b[i][j];
        }
    }
}

void printArray(float a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    ifstream in;
    in.open("input.txt");
    int length;
    in >> length;
    float *a = new float[length];
    for(int i=0;i<length;i++)
    {
        in >> a[i];
    }
    in.close();
    BucketSort(a,length);
    ofstream out;
    out.open("output.txt");
    for(int i=0;i<length;i++)
    {
        out << a[i] <<"\n";
    }
    out.close();

    return 0;
}
