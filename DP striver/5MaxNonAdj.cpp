#include <bits/stdc++.h>
using namespace std;
int solve(int ind, vector<int> &nums)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    int pick = solve(ind - 2, nums) + nums[ind];
    int notpick = solve(ind - 1, nums);
    return max(pick, notpick);
}
int maxnonadj(vector<int> &nums)
{
    int n = nums.size();
    return solve(n - 1, nums);
}
int main()
{
    cout << "Enter number of elements: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << "Max sum of non adjacent elements is: " << maxnonadj(nums);
    return 0;
}