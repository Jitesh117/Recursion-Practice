#include<bits/stdc++.h>
using namespace std;
int main()
{
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
        
    cout << "Minimum number of insertions and deletion required:\n" << m+n-2*t[n][m];
    return 0;
}