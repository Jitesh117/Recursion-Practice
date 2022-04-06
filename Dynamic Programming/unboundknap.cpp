#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,W;
    cout <<"Enter the number of items:\n";
    cin >> n;
    int val[n],wt[n];
    cout <<"Enter the weights:\n";
    for(int i = 0;i<n;i++)
        cin >> wt[i];
    cout <<"Enter the values:\n";
    for(int i = 0;i<n;i++)
        cin >> val[i];
    cout <<"Enter the max capacity:\n";
    cin >> W;
    int t[n+1][W+1];
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=W;j++)
            t[i][j] = 0;
    
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=W;j++)
        {
            if(wt[i-1]<=j)
            {
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]],t[i-1][j]);
            }
            else
                t[i][j] = t[i-1][j];
        }

    cout <<"Max profit is:" << t[n][W];

    return 0;
}