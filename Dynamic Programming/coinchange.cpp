#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of coins: ";
    cin >> n;
    vector<int> coin;
    for (int i = 0; i < n;i++)
        cin >> coin[i];
    int sum;
    cin >> sum;
    vector<int> value(n + 1);
    value[0] = 0;
    for (int i = 1; i <= n;i++)
    {
        value[n] = INT_MAX;
        for(auto x: coin)
        {
            if(i-x>=0)
                value[x] = min(value[x], value[x - c]);
                
        }
    }
}