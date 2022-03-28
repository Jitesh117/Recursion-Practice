#include<bits/stdc++.h>
using namespace std;
bool IsSubsetsum(int arr[],int sum,int n)
{
    bool t[n+1][sum+1];
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=sum;j++)
        {
            if( i == 0)
             t[i][j] == false;
            if( j == 0)
             t[i][j] == true;
        }
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=sum;j++)
      {
          if(arr[i-1]<=j)
                 t[i][j] = (t[i][j - arr[i-1]] || t[i-1][j]);
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
    int arr[n];
    cout << "Enter the values: \n";
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    int sum;
    cout << "Enter the sum:\n";
    cin >> sum;
    int total=0;
    for(int i = 0;i<n;i++)
        total+=arr[i];
    if(total%2!=0)
      cout << "False";
    else
    {
    if(IsSubsetsum(arr,sum,n) == true)
        cout <<"True";
    else
        cout << "False";
    }
    
    return 0;
}