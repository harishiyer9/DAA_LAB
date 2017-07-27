#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int count = 0;

void swap(int* a,int left,int right)
{
  int temp;
  temp = a[left];
  a[left] = a[right];
  a[right] = temp;
}

int partition(int* a,int low,int high)
{
  int key;
  swap(a,low,high);
  key = a[high];
  int i,j;
  i = low-1;
  for(j=low;j<high;j++)
   {
      if(a[j] < key)
      {
       i++;
       swap(a,i,j);
       count++;
      }  
   } 
   swap(a,i+1,high);
   return i+1;
}


void QuickSort(int* a,int low,int high)
{
  int pivot;
  if(high > low)
  {
     pivot = partition(a,low,high);
     QuickSort(a,low,pivot-1);
     QuickSort(a,pivot+1,high);
  }
}

void printarray(int* a,int n)
{
  int i;
  for(i=0;i<n;i++)
    printf("%d ", a[i]);
  printf("\n");  
}


int main()
{
   int n,i;
   ifstream in;
   in.open("input.txt");
   in>>n;
   int *a = new int[n];
   for(i=0;i<n;i++)
   {
   		in>>a[i];
   }
   in.close();
   QuickSort(a,0,n-1);
   ofstream out;
   out.open("outputl.txt");
   for(i=0;i<n;i++)
   {
   		out<<a[i]<<"\n";
   }
   out<<"The number of swaps in the main for loop of the partition procedure is ";
   out<<count;
   out.close();
   cout<<count;
   
   
   
 
   return 0; 
}
