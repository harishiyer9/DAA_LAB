#include<stdio.h>
#include<iostream>
#include<fstream>
#include <vector>
using namespace std;


int main()
{
  int n1,n2,n3;
  ifstream in;
  in.open("input.txt");
  in>>n1;
  int *a1 = new int [n1];
  for(int i=0;i<n1;i++)
  {
  	in>>a1[i];
  }
  in>>n2;
  int *a2 = new int [n2];
  for(int i=0;i<n2;i++)
  {
  	in>>a2[i];
  }
  in>>n3;
  int *a3 = new int [n3];
  for(int i=0;i<n3;i++)
  {
  	in>>a3[i];
  }
  
  vector<int> v;
  int i=0,j=0,k=0;
  int cmp=0;
  while(i<n1 && j<n2 && k<n3)
  {
  	if(a1[i] == a2[j])
  	{
  		cmp++;
  		while(k<n3)
  		{
  			if(a1[i] == a3[k])
  			{
  				cmp++;
  				v.push_back(a1[i]);
  				i++;
  				k++;
  				j++;
  				break;	
  			}
  			else if(a1[i] > a3[k])
  			{
  				k++;
  				cmp++;
  			}
  			else
  			{
  				i++;
  				j++;
  				break;
  			}
  		}
  	}
  	else if(a1[i] > a2[j])
  	{
  		j++;
  		cmp++;
  	}
  	else
  	{
  		i++;
  	}
  }

  for(int i=0;i<v.size();i++)
  {
  	cout<<"The common element(s) is/are : "<<v[i]<<"\n";
  }
  cout<<"The number of comparisions are: "<<cmp<<"\n";
 


  return 0;
}
