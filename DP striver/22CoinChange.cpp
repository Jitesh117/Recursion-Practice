#include <bits/stdc++.h>
using namespace std;
long recursion(int ind, int T, int *denomimnations)
{
    if (ind == 0)
        return T % denomimnations[0] == 0;

    long nontake = recursion(ind - 1, T, denomimnations);
    long take = 0;
    if (denomimnations[ind] <= T)
        take = recursion(ind, T - denomimnations[ind], denomimnations);

    return take + nontake;
}

long memoized(int ind, int T, int *denomimnations, vector<vector<int>> &dp)
{
    if (ind == 0)
        return T % denomimnations[0] == 0;

    if (dp[ind][T] != -1)
        return dp[ind][T];
    long nontake = recursion(ind - 1, T, denomimnations);
    long take = 0;
    if (denomimnations[ind] <= T)
        take = recursion(ind, T - denomimnations[ind], denomimnations);

    return dp[ind][T] = take + nontake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int T = 0; T <= value; T++)
        dp[0][T] = (T % denominations[0] == 0);
    for (int ind = 1; ind < n;ind++){
        for (int T = 0; T <= value;T++)
        {
            long nontake = dp[ind - 1][T];
            long take = 0;
            if(denominations[ind] <= T)
                take = dp[ind][T - denominations[ind]];
            dp[ind][T] = take + nontake;
        }
    }
    return dp[n - 1][value];

    // return recursion(n - 1, value, denominations);
}
