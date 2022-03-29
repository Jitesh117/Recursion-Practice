#include<bits/stdc++.h>
using namespace std;
int t[102][1002];
int knapsack(int wt[], int val[], int W, int n)
{
    if(W==0 || n ==0)
        return 0;
    if(t[n][W]!=-1)
        return t[n][W];
    if(wt[n-1]<=W)
    {
        t[n][W] = max(val[n-1]+ knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
        return t[n][W];
    }
    else
     {
         t[n][W] = knapsack(wt,val,W,n-1);
         return t[n][W];
     }
}

int main()
{
    memset(t,-1,sizeof(t));
    int n,W;
    cout <<"Enter the number of items :\n";
    cin >> n;
    int wt[n],val[n];
    cout <<"Enter the weights:\n";
    for(int i = 0;i<n;i++)
     cin >> wt[i];
    cout <<"Enter the values :\n";
    for(int i = 0;i<n;i++)
     cin >> val[i];
    cout <<"Enter the weight carrying capacity of the knapsack: \n";
    cin >> W;
    cout << "The max profit is: " << knapsack(wt,val,W,n);

    return 0;
}