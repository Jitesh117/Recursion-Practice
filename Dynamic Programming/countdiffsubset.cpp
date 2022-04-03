#include<bits/stdc++.h>
using namespace std;
int countsubset(int arr[],int sum,int n)
{
    int t[n+1][sum+1];
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=sum;j++)
        {
            if( i == 0)
             t[i][j] =0;
            if( j == 0)
             t[i][j] = 1;
        }
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=sum;j++)
      {
          if(arr[i-1]<=j)
                 t[i][j] = (t[i-1][j - arr[i-1]] + t[i-1][j]);
          else
                 t[i][j] = t[i-1][j];
      }
    return t[n][sum];
}

int main()
{
    int n;
    cout <<"Enter the size:\n";
    cin >> n;
    int arr[n],sum=0;
    cout << "Enter the values: \n";
    for(int i = 0;i<n;i++)
        {
            cin >> arr[i];
            sum+=arr[i];
        }
    int diff;
    cout <<"Enter the difference:\n";
    cin>> diff;
    cout <<"Number of subsets of given sum:\n" << countsubset(arr,(diff+sum)/2,n);
    
    return 0;
}