#include<bits/stdc++.h>
using namespace std;
// int sum = 0;
void print(int n,int sum)
{
    if( n <1)
        {
            cout << sum;
            return;
        }
    sum += n;
    print(n - 1,sum);
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    print(n,0);
    // cout << sum;
    return 0;
}