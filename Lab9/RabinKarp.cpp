#include <iostream>
#include <string>
#include <math.h>

using namespace std;



void RabinKarp(string P, string T,int d, int q)
{
    int m = P.length();
    int n = T.length();
    int h = (int)pow(d,m-1)%q;
    int p = 0;
    int t = 0;
    int j,i;

    for (i = 0; i < m; i++)
    {
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }
    for (int s = 0; s <= n - m; s++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (T[s + j] != P[j])
                    break;
            }
            if (j == m)
            {
                cout<<"Pattern occurs with shift : "<<s<<endl;
            }
        }
        if (i < n - m)
        {
            t = (d * (t - T[s] * h) + T[s + m]) % q;
            if (t < 0)
              t = (t + q);
        }
    }
}


int main()
{
    string T = "123456789123456789123456789123456789";
    string P = "1234";
    int d = 10;
    int q = 101;
    RabinKarp(P,T,d,q );
    return 0;
}
