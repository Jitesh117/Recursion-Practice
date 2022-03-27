#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,W;
    cout << "Enter the number of items:\n";
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
    
    int t[n+1][W+1];
    for(int i = 0;i<n+1;i++)
        for(int j = 0;j<W+1;j++)
          if(i == 0 || j == 0)
            t[i][j] = 0;
    for(int i =1;i<n+1;i++)
        for(int j = 1;j<W+1;j++)
         {
             if(wt[i-1]<=j)
                {
                    t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                }
            else
                t[i][j] = t[i-1][j];
         }
    cout << "The max profit is: "<< t[n][W];
    return 0;
}