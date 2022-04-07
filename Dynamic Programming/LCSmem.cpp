#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int LCS(string x, string y, int n, int m)
{
    if( n == 0 || m == 0)
      t[n][m] = 0;
    
    if(t[n][m] != -1)
        return t[n][m];
    else{
        if(x[n-1] == y[m-1])
         t[n][m] =  1 + LCS(x,y,n-1,m-1);
        else
            t[n][m] = max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
    }
    return t[n][m];
}
int main()
{
    string x,y;
    cout <<"Enter the two strings:\n";
    cin >> x >> y;
    memset(t, -1, sizeof(t)); 
    cout <<"The number of letters in the LCS is:\n"<< LCS(x,y,x.size(),y.size());
    return 0;
}