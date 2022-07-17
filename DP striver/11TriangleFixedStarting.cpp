#include <bits/stdc++.h>
using namespace std;
// Recursion
int triangle(int i, int j, int n, vector<vector<int>> &a)
{
    if (i == n - 1)
    {
        return a[i][j];
    }
    int d = a[i][j] + triangle(i, j + 1, n, a);
    int dg = a[i][j] + triangle(i + 1, j + 1, n, a);
    return min(d, dg);
}

// Memoization
int triangle(int i, int j, int n, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return a[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int d = a[i][j] + triangle(i, j + 1, n, a, dp);
    int dg = a[i][j] + triangle(i + 1, j + 1, n, a, dp);

    return dp[i][j] = min(d, dg);
}

// Tabulation

int main()
{
    vector<vector<int>> a;
    int n, m;
    cin >> n >> m;
    int dp[n][m];
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = a[n - 1][j];
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j++)
        {
            int d = a[i][j] + dp[i + 1][j];
            int dg = a[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(d, dg);
        }
    }
    cout << dp[0][0];
    return 0;
}