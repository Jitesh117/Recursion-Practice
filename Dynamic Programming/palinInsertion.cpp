#include<bits/stdc++.h>
using namespace std;
int main()
{
    string one,two;
    cout <<"Enter the string:\n";
    cin>> one;
    two = one;
    reverse(two.begin(),two.end());
    int n = one.size();
    int t[n+1][n+1]; 
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=n;j++)
        if(i == 0 || j == 0)
            t[i][j] = 0;
    
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
        {
            if(one[i-1] == two[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    cout<<"Minimum number of insertions to make the string palindrome:\n" << n-t[n][n];

    return 0;
}