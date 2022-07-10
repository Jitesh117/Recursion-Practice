#include<bits/stdc++.h>
using namespace std;
void printnum(int n)
{
    if( n <1)
        return;
    cout << n << " ";
    printnum(n - 1);
    
}
int main()
{
    int n;
    cout << "Enter value of n";
    cin >> n;
    printnum(n);
    return 0;
}