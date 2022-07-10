#include<bits/stdc++.h>
using namespace std;
int  print(int n)
{
    if(n == 1)
        return 1;
    return n + print(n - 1);
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << print(n);
    return 0;
    
}