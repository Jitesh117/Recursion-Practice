#include<bits/stdc++.h>
using namespace std;
class Recursive{
    int solve(int ind, int sum, vector<int> &nums)
    {
        if (sum == 0)
            return 1;
        if (ind == 0)
            return nums[ind] == sum;
        int take = 0;
        int nontake = solve(ind - 1, sum, nums);
        if (nums[ind] <= sum)
            take = solve(ind - 1, sum - nums[ind], nums);
        return take + nontake;
    }
    int findWays(vector<int> &num, int tar)
    {
        int n = num.size();
        return solve(n - 1, tar, num);
    }
};
class Memoized{
    int solve(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return 1;
        if (ind == 0)
            return nums[ind] == sum;
        if (dp[ind][sum] != -1)
            return dp[ind][sum];
        int take = 0;
        int nontake = solve(ind - 1, sum, nums, dp);
        if (nums[ind] <= sum)
            take = solve(ind - 1, sum - nums[ind], nums, dp);
        return dp[ind][sum] = take + nontake;
    }
    int findWays(vector<int> &num, int tar)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        return solve(n - 1, tar, num, dp);
    }
};

class Tabulation{

    int findWays(vector<int> &num, int tar)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1));
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        if (num[0] <= tar)
            dp[0][num[0]] = 1;
        for (int i = 1; i < n; i++)
            for (int sum = 0; sum <= tar; sum++)
            {
                int nontake = dp[i - 1][sum];
                int take = 0;
                if (num[i] <= sum)
                    take = dp[i - 1][sum - num[i]];
                dp[i][sum] = take + nontake;
            }
        return dp[n - 1][tar];
    }
};