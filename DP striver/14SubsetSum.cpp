#include <bits/stdc++.h>
using namespace std;

// Recursive solution

class Solution
{
public:
    bool solve(int ind, int k, vector<int> &arr)
    {
        if (k == 0)
            return true;
        if (ind == 0)
            return (arr[0] == k);

        bool nontake = solve(ind - 1, k, arr);
        bool take = false;
        if (arr[ind] <= k)
            take = solve(ind - 1, k - arr[ind], arr);

        return (take or nontake);
    }
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        return solve(n - 1, k, arr);
    }
};

// Memoized solution

class Solution2
{
public:
    bool solve(int ind, int k, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (k == 0)
            return true;
        if (ind == 0)
            return (arr[0] == k);
        if (dp[ind][k] != -1)
            return dp[ind][k];
        bool nontake = solve(ind - 1, k, arr, dp);
        bool take = false;
        if (arr[ind] <= k)
            take = solve(ind - 1, k - arr[ind], arr, dp);

        return dp[ind][k] = (take or nontake);
    }
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(n - 1, k, arr, dp);
    }
};

// Tabulation method

class Solution3
{
public:
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        dp[0][arr[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= k; target++)
            {
                bool nontake = dp[ind - 1][target];
                bool take = false;
                if (arr[ind] <= target)
                    take = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = take | nontake;
            }
        }
        return dp[n - 1][k];
    }
};
