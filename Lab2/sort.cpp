#include <iostream>
#include <fstream>

using namespace std;



void SelectionSort(int a[],int n)
{
    int min_idx,temp;
    for(int i=0;i<n-1;i++)
    {
        min_idx=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min_idx])
            {
                min_idx=j;
            }
        }
        temp=a[min_idx];
        a[min_idx]=a[i];
        a[i]=temp;
    }
}


void Merge(int a[],int aux[],int low,int mid,int high)
{
    for(int k=low; k<=high; k++)
    {
        aux[k] = a[k];
    }
    int i = low,j=mid+1;
    for(int k=low; k<=high; k++)
    {
        if(i>mid)
        {
            a[k] = aux[j++];
        }
        else if(j>high)
        {
            a[k] = aux[i++];
        }
        else if(aux[i]<=aux[j])
        {
            a[k] = aux[i++];
        }
        else
        {
            a[k] = aux[
            j++];
        }
    }
}

void Sort(int a[],int aux[],int low,int high)
{
    if(low<high)
    {
        int mid = low+(high-low)/2;
        Sort(a,aux,low,mid);
        Sort(a,aux,mid+1,high);
        Merge(a,aux,low,mid,high);
    }
}

void MergeSort(int a[],int n)
{
	int *aux = new int[n];
	Sort(a,aux,0,n-1);
}
int Partition(int a[],int low,int high)
{
    int key = a[high];
    int i = low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<key)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void QuickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int key = Partition(a,low,high);
        QuickSort(a,low,key-1);
        QuickSort(a,key+1,high);
    }
}


void InsertionSort(int a[],int length)
{
    for(int i=0;i<length;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
            }
            else
            {
                break;
            }
        }
    }
}



int main()
{

    int n;
    cout<<"Enter the type of sort you want to choose\n";
    cout<<"Press 1 for Merge Sort\n";
    cout<<"Press 2 for Quick Sort\n";
    cout<<"Press 3 for Insertion Sort\n";
    cout<<"Press 4 for Selection Sort\n";
    cin>>n;
    ifstream in;
    in.open("input.txt");
    int length;
    in >> length;
    int *a = new int[length];
    for(int i=0;i<length;i++)
    {
        in >> a[i];
    }
    in.close();
    if(n==1)
    {
        MergeSort(a,length);
    }
    if(n==2)
    {
        QuickSort(a,0,length-1);
    }
    if(n==3)
    {
        InsertionSort(a,length);
    }
    if(n==4)
    {
        SelectionSort(a,length);
    }
    ofstream out;
    out.open("output.txt");
    for(int i=0;i<length;i++)
    {
        out << a[i] <<"\n";
    }
    out.close();


    return 0;
}
