#include<bits/stdc++.h>
using namespace std;
void revarr(int i,int arr[],int n)
{
    if(i>=n/2)
        return;
    swap(arr[i], arr[n - i-1]);
    revarr(i + 1, arr, n);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    revarr(0, arr, n);
    cout << endl;
    for(auto i: arr)
        cout << i << " ";
    return 0;
}