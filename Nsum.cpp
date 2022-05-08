#include<bits/stdc++.h>
using namespace std;
int nsum(int n)
{
    if(n==1)
        return 1;
    int sum=n;
    sum+=nsum(n-1);
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << nsum(n);
    return 0;
}