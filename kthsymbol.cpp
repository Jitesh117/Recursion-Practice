#include<bits/stdc++.h>
using namespace std;
int kthsymbol(int n ,int k)
{
    if(n==1 && k==1)
        return 0;
    int mid = pow(2,n-1)/2;
    
    if(k<=mid)
        return kthsymbol(n-1,k);
    else
        return !kthsymbol(n-1,k-mid);
}
int main()
{
    int n , k;
    cout <<"Enter the value of n and k: ";
    cin >> n >> k;
    int ans = kthsymbol(n,k);
    cout<<"The kth symbol of grammar is: " << ans;
    return 0;
}