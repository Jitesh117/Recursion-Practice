#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,N;
    cout <<"Enter the length of rod:\n";
    cin >> n;
    int price[n],length[n];
    cout <<"Enter the rate of the rod length wise\n";
    for(int i = 0 ;i<n;i++)
        cin >> price[i];
    for(int i = 1;i<=n;i++)
        length[i-1] = i;
    int t[n+1][n+1];
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=n;j++)
            t[i][j]=0;
    for(int  i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
        {
            if(length[i-1]<=j)
            {
                t[i][j] = max(price[i-1] + t[i][j-length[i-1]],t[i-1][j]);
            }
            else
                t[i][j] = t[i-1][j];
        }
    cout <<"The max profit in rod cutting is:" << t[n][n];

    return 0;
}