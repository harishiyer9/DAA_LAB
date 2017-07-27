#include<iostream>
#include<fstream>


using namespace std;

void Isolated(int **a,int n)
{
	int count1[n],count2[n],count=0;
	for(int i=0;i<n;i++)
	{
		count1[i] = 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			count1[i] += a[i][j];
		}
	}

	for(int i=0;i<n;i++)
	{
		count2[i] = 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			count2[i] += a[j][i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(count1[i] == 0 && count2[i] == 0)
		{
			cout<<"Vertex "<<i+1<<" is  a isolated node\n";
			count++;
		}
	}
	cout<<"The number of isolated nodes are "<<count;
}

int main()
{
   int n;
   ifstream in;
   in.open("input.txt");
   in>>n;
   int **a = new int*[n];
   for(int i=0;i<n;i++)
   {
		   a[i] = new int[n];
   }
   for(int i=0;i<n;i++)
   {
	    for(int j=0;j<n;j++)
	    {
			in>>a[i][j];
		}
   }
   in.close();
   Isolated(a,n);


	return 0;
}
