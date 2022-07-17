#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    int minFallingPathSum(vector<vector<int>> &v)
    {
        n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int result = INT_MAX;
        for (int j = 0; j < n; j++)
            result = min(result, solve(v, 0, j, dp));
        return result;
    }

    // Memoization

    int solve(vector<vector<int>> &v, int i, int j, vector<vector<int>> &dp)
    {
        if (j < 0 or j == n)
            return INT_MAX;
        if (i == n - 1)
            return v[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int dleft = solve(v, i + 1, j - 1, dp);
        int dright = solve(v, i + 1, j + 1, dp);
        int down = solve(v, i + 1, j, dp);

        return dp[i][j] = min(dleft, min(dright, down)) + v[i][j];
    }
};
// Tabulation
int minFallingPathSum(vector<vector<int>> &v)
{
    int n = v.size();
    int result = INT_MAX;
    int dp[n][n];
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = v[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            int down = INT_MAX, left = INT_MAX, right = INT_MAX;

            down = dp[i + 1][j];
            if (j - 1 >= 0)
                left = dp[i + 1][j - 1];
            if (j + 1 < n)
                right = dp[i + 1][j + 1];
            dp[i][j] = min(down, min(left, right)) + v[i][j];
        }
    }
    for (int j = 0; j < n; j++)
        result = min(dp[0][j], result);

    return result;
}