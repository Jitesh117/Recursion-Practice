#include<bits/stdc++.h>
using namespace std;
int Solve(int arr[],int i,int j)
{
    if(i>=j)
        return 0;
    int ans = INT_MAX;
    for(int k = i;k<=j-1;k++)
    {
       int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		ans = min(ans, temp_ans);
    }
    return ans;
}
int main()
{
    int n;
    cout <<"Enter the size of the array:\n";
    cin >> n;
    int arr[n];
    cout <<"Enter the elements of the array:\n";
    for(int i  =0;i<n;i++)
        cin >> arr[i];
    // solve(arr,1,n-1);
    cout <<"minimum cost of multiplication:\n";
    cout << Solve(arr,1,n-1);

    return 0;

}
