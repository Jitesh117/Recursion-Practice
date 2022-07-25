#include <bits/stdc++.h>
using namespace std;
class Recursive
{
    int solve(int ind, int w, vector<int> &wt, vector<int> &val)
    {
        if (ind == 0)
        {
            if (wt[0] <= w)
                return val[0];
            return 0;
        }
        int nontake = solve(ind - 1, w, wt, val);
        int take = INT_MIN;
        if (wt[ind] <= w)
            take = val[ind] + solve(ind - 1, w - wt[ind], wt, val);

        return max(take, nontake);
    }

    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        return solve(n - 1, maxWeight, weight, value);
    }
};

class Memoized
{
    int solve(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (wt[0] <= w)
                return val[0];
            return 0;
        }
        if (dp[ind][w] != -1)
            return dp[ind][w];
        int nontake = solve(ind - 1, w, wt, val, dp);
        int take = INT_MIN;
        if (wt[ind] <= w)
            take = val[ind] + solve(ind - 1, w - wt[ind], wt, val, dp);

        return dp[ind][w] = max(take, nontake);
    }

    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
        return solve(n - 1, maxWeight, weight, value, dp);
    }
};
class Tabulation
{
    int knapsack(vector<int> wt, vector<int> value, int n, int maxWeight)
    {
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
        for (int w = wt[0]; w <= maxWeight; w++)
            dp[0][w] = value[0];
        for (int ind = 1; ind < n; ind++)
            for (int w = 0; w <= maxWeight; w++)
            {
                int nontake = dp[ind - 1][w];
                int take = INT_MIN;
                if (wt[ind] <= w)
                    take = value[ind] + dp[ind - 1][w - wt[ind]];

                dp[ind][w] = max(take, nontake);
            }
        return dp[n - 1][maxWeight];
    }
};