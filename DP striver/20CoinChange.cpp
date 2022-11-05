#include<bits/stdc++.h>
using namespace std;
class Tabulation
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1));
        for (int i = 0; i <= amount; i++)
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        for (int i = 1; i < n; i++)
            for (int target = 0; target <= amount; target++)
            {
                int nontake = dp[i - 1][target];
                int take = 1e9;
                if (coins[i] <= target)
                    take = 1 + dp[i][target - coins[i]];
                dp[i][target] = min(take, nontake);
            }
        if (dp[n - 1][amount] >= 1e9)
            return -1;
        return dp[n - 1][amount];
    }
};
class Recursive
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = solve(n - 1, coins, amount, dp);
        if (result >= 1e9)
            return -1;
        return result;
    }
    int solve(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (amount % coins[ind] == 0)
                return amount / coins[ind];
            return INT_MAX;
        }
        if (dp[ind][amount] != -1)
            return dp[ind][amount];
        int nontake = solve(ind - 1, coins, amount, dp);
        int take = 1e9;
        if (coins[ind] <= amount)
            take = 1 + solve(ind, coins, amount - coins[ind], dp);

        return dp[ind][amount] = min(take, nontake);
    }
};