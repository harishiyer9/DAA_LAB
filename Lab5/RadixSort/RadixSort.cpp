#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

int Find_Max(int a[], int n)
{
    int max = a[0];
    int i;
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void CountingSort(int a[], int n, int exp)
{
    int output[n],c[10];
    for(int i=0; i<10; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        c[(a[i] / exp) % 10]++;
    }


    for (int i = 1; i < 10; i++)
    {
        c[i] += c[i - 1];
    }


    for (int i = n - 1; i >= 0; i--)
    {
        output[c[(a[i] / exp) % 10] - 1] = a[i];
        c[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}


void RadixSort(int a[], int n)
{

    int m = Find_Max(a, n);
    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
    {
        CountingSort(a, n, exp);
    }

}


int main()
{
    ifstream in;
    in.open("input.txt");
    int length,k;
    in >> length;
    int *a = new int[length];
    for(int i=0;i<length;i++)
    {
        in >> a[i];
    }
    in.close();
    RadixSort(a,length);
    ofstream out;
    out.open("output.txt");
    for(int i=0;i<length;i++)
    {
        out << a[i] <<"\n";
    }
    out.close();
}
