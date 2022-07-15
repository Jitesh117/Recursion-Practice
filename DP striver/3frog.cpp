#include <bits/stdc++.h>
using namespace std;
int frog(int ind, vector<int> &heights, vector<int> dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int left = frog(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = frog(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);

    return dp[ind] = min(left, right);
}
// Tabulation
int frogjump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}
// Space Optimisation
int fjump(int n, vector<int> &heights)
{
    int prev2 = 0;
    int prev1 = 0;
    for (int i = 1; i < n; i++)
    {
        int left = prev2 + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev1 + abs(heights[i] - heights[i - 2]);

        int curi = min(left, right);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}