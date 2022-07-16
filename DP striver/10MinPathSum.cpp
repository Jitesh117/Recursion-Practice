#include <bits/stdc++.h>
using namespace std;
int solve(int m, int n, vector<vector<int>> &grid)
{
    int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = grid[i][j] + dp[i - 1][j];
                if (j > 0)
                    left = grid[i][j] + dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}
