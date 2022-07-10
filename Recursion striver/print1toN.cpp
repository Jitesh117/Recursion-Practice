#include<bits/stdc++.h>
using namespace std;
// int count = 0;
void printnum(int n,int count)
{
    if(count > n)
        return ;
    cout << count << " ";
    printnum(n, count + 1);
}
int main()
{
    int n;
    cout << "Enter value of n";
    cin >> n;
    printnum(n, 1);
    return 0;
}