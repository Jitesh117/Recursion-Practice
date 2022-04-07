#include<bits/stdc++.h>
using namespace std;
int LCS(string x, string y, int n, int m)
{
    if( n == 0 || m == 0)
        return 0;
    else{
        if(x[n-1] == y[m-1])
            return 1 + LCS(x,y,n-1,m-1);
        else
            return max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
    }
}
int main()
{
    string x,y;
    cout <<"Enter the two strings:\n";
    cin >> x >> y;
    cout <<"The number of letters in the LCS is:\n"<< LCS(x,y,x.size(),y.size());
    return 0;
}