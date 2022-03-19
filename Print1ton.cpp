#include<bits/stdc++.h>
using namespace std;
void printn(int n)
{
    if(n==0)
        return;
    printn(n-1);
    cout<< n << " ";    
}
int main()
{
    int n;
    cout<<"Enter the value of n \n";
    cin >> n;
    printn(n);
}