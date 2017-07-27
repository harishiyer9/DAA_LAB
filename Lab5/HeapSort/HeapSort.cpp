#include <iostream>
#include <fstream>

using namespace std;

int Parent(int index)
{
    return index/2;
}

int Left(int index)
{
    return 2*index;
}

int Right(int index)
{
    return 2*index+1;
}

void MaxHeapify(int a[],int i,int HeapSize)
{
    int largest;
    int l = Left(i),r = Right(i);
    if(l<HeapSize && a[l]>a[i])
    {
        largest = l;
    }
    else
    {
        largest= i;
    }
    if(r<HeapSize && a[r]>a[largest])
    {
        largest = r;
    }
    if(largest !=i)
    {
        swap(a[i],a[largest]);
        MaxHeapify(a,largest,HeapSize);
    }
}

void BuildMaxHeap(int a[],int length)
{
    for(int i=length/2;i>=1;i--)
    {
        MaxHeapify(a,i,length);
    }
}

void HeapSort(int a[],int length)
{
    BuildMaxHeap(a,length);
    int HeapSize = length;
    for(int i=length;i>=2;i--)
    {
       swap(a[1],a[i]);
       HeapSize--;
       MaxHeapify(a,1,HeapSize);
    }
}

void printArray(int a[],int n)
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
    int *a = new int[length+1];
    for(int i=1;i<=length;i++)
    {
        in >> a[i];
    }
    in.close();
    HeapSort(a,length);
    ofstream out;
    out.open("output.txt");
    for(int i=1;i<=length;i++)
    {
        out << a[i] <<"\n";
    }
    out.close();

    return 0;
}
