#include<bits/stdc++.h>
using namespace std;
int minsubset(int arr[], int Range,int n)
{   bool t[n][Range];
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=Range;j++)
        {
            if(i == 0)
                t[i][j] = false;
            if(j == 0)
                t[i][j] = true;
        }
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=Range;j++)
        {
            if(arr[i-1]<=j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else
            t[i][j] = t[i-1][j];
        }
    vector<int> v;
    int minsum = INT_MAX;
    for(int i = 0;i<=Range/2;i++)
        if(t[n][i] == true)
            v.push_back(i);
    for(int i = 0;i<v.size();i++)
       minsum = min(minsum,Range-2*v[i]);
    
    return minsum;
}

int main()
{
     int n;
    cout << "Enter the size:\n";
    cin>> n;
    int arr[n];
    int Range = 0;
    cout <<"Enter the values:\n";
    for(int i = 0;i<n;i++)
       {
            cin >> arr[i];
            Range+=arr[i];
       }
    cout << "The minimum difference of sum of subsets is: " << minsubset(arr,Range,n);

    return 0; 
}