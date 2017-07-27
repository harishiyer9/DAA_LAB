#include <iostream>
#include <limits.h>
#include <stdio.h>

using namespace std;

int s[50][50];

int MatrixChainOrder(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;

    for (i=1; i<n; i++)
        m[i][i] = 0;

    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }

            }
        }
    }
}

void Print(int s[50][50],int i,int j)
{
    if(i==j)
    {
        printf("A%d",i);
    }
    else
    {
        printf("(");
        Print(s,i,s[i][j]);
        Print(s,s[i][j]+1,j);
        printf(")");
    }
}
int main()
{
    int p[] = {30,35,15,5,10,20,25};
    MatrixChainOrder(p,7);
    Print(s,1,6);

    return 0;
}
