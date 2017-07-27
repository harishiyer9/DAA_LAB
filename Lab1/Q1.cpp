#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

int Find_Max(int arr[], int i, int n)
{
	if(i == n-1) return arr[i];
	else return max(arr[i], Find_Max(arr,i+1,n));
}

int main()
{
	int n;
	ifstream in;
	in.open("input.txt");
	in>>n;
	int *a = new int[n];
	for(int i=0; i<n;i++) 
	{
		in>>a[i];
	}
	in.close();
	cout<<"The maximum element in the array is : "<<Find_Max(a,0,n)<<"\n";
	
	

	
	return 0;
}