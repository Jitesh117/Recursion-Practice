#include <bits/stdc++.h>
using namespace std;
// NOTE: Think of it as collect rod lengths and make it n instead of cutting it.

int recursion(int ind, vector<int> &price, int n)
{
    if (ind == 0)
        return n * price[0];
    int nontake = recursion(ind - 1, price, n);
    int take = INT_MIN;
    int rodlength = ind + 1;
    if (rodlength <= n)
        take = price[ind] + recursion(ind, price, n - rodlength);
    return max(take, nontake);
}
int memoized(int ind, vector<int> &price, int n, vector<vector<int>> &dp)
{
    if (ind == 0)
        return n * price[0];
    if (dp[ind][n] != -1)
        return dp[ind][n];
    int nontake = memoized(ind - 1, price, n, dp);
    int take = INT_MIN;
    int rodlength = ind + 1;
    if (rodlength <= n)
        take = price[ind] + memoized(ind, price, n - rodlength, dp);
    return dp[ind][n] = max(take, nontake);
}
// Tabulated
int cutRod(vector<int> &price, int n)
{
    int dp[n][n + 1];
    for (int i = 0; i <= n; i++)
        dp[0][i] = i * price[0];
    for (int i = 1; i < n; i++)
    {
        for (int N = 0; N <= n; N++)
        {
            int nontake = dp[i - 1][N];
            int take = INT_MIN;
            int rodlen = i + 1;
            if (rodlen <= N)
                take = price[i] + dp[i][N - rodlen];
            dp[i][N] = max(take, nontake);
        }
    }
    return dp[n - 1][n];
}