#include <bits/stdc++.h>
using namespace std;
int solve(int ind, vector<int> &nums, vector<int> &dp) // memoization
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int pick = solve(ind - 2, nums, dp) + nums[ind];
    int notpick = solve(ind - 1, nums, dp);
    return dp[ind] = max(pick, notpick);
}
int maxnonadj(vector<int> &nums, vector<int> &dp)
{
    int n = nums.size();
    return solve(n - 1, nums, dp);
}
int main()
{
    cout << "Enter number of elements: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    // vector<int> dp(n, -1);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    // Tabulation
    vector<int> dp(n);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int take = nums[i];
        if (i > 1)
            take += dp[i - 2];
        int nontake = dp[i - 1];
        dp[i] = max(take, nontake);
    }

    // Space optimisation
    int prev2 = 0, prev = nums[0];
    for (int i = 1; i < n; i++)
    {
        int take = nums[i];
        if (i > 1)
            take += prev2;
        int nontake = prev;
        int curi = max(take, nontake);
        prev2 = prev;
        prev = curi;
    }
    // cout << "Max sum of non adjacent elements is: " << maxnonadj(nums, dp);
    // cout << "Max sum of non adjacent elements is: " << dp[n - 1];
    cout << "Max sum of non adjacent elements is: " << prev;
    return 0;
}