#include <bits/stdc++.h>
using namespace std;
class Memoization
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = 1;
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return solve(0, prices, 1, dp);
    }
    int solve(int ind, vector<int> &prices, int buy, vector<vector<int>> &dp)
    {
        if (ind == prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy)
        {
            profit = max(-prices[ind] + solve(ind + 1, prices, 0, dp), solve(ind + 1, prices, 1, dp));
        }
        else
            profit = max(prices[ind] + solve(ind + 1, prices, 1, dp), solve(ind + 1, prices, 0, dp));
        return dp[ind][buy] = profit;
    }
};

class Tabulation
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = 1;
        int n = prices.size();
        int dp[n + 1][2];
        dp[n][0] = dp[n][1] = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                }
                else
                    profit = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);

                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};