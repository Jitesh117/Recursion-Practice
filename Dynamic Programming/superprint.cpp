#include<bits/stdc++.h>
using namespace std;
int main()
{
    string result;
    
    string x,y;
    cout <<"Enter the two strings:\n";
    cin >> x >> y;
    int m = y.size(),n = x.size();
    int t[n+1][m+1];

    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=m;j++)
          if(i == 0 || j == 0)
            t[i][j]  = 0;

    for(int i = 1;i<=n;i++)
        for(int j= 1;j<=m;j++)
        {
          if(x[i-1] == y[j-1])
              t[i][j] = 1+t[i-1][j-1];
          else
              t[i][j] = max(t[i-1][j],t[i][j-1]);

        }
      int i =n,j=m;
   while(i>0 && j>0)
        {
            if(x[i-1] == y[j-1])
                {
                    result.push_back(x[i-1]);
                    i--,j--;
                }
            else
            {
                if(t[i-1][j]>t[i][j-1])
                    {
                        result.push_back(x[i-1]);
                        i--;
                    }
                else
                    {
                        result.push_back(y[j-1]);
                        j--;
                    }
            }
        }
    while(i>0)
    {
        result.push_back(x[i-1]);
        i--;
    }
    while(j>0)
    {
        result.push_back(y[j-1]);
        j--;
    }
        reverse(result.begin(),result.end());
    cout <<"The LCS is:\n" << t[n][m];
    cout <<"\nThe smallest supersuquence is:\n"<< result;
}