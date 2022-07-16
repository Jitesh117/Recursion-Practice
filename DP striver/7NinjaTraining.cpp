#include <bits/stdc++.h>
using namespace std;

// Recursive

int ninja(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[day][last] = maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (last != i)
        {
            int point = points[day][i] + ninja(day - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

// Memoization

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return ninja(n - 1, 3, points, dp);
}

// Tabulation

int ninjaTraining(int n, vector<vector<int>> &v)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(v[0][1], v[0][2]);
    dp[0][1] = max(v[0][0], v[0][2]);
    dp[0][2] = max(v[0][1], v[0][0]);
    dp[0][3] = max(v[0][1], max(v[0][0], v[0][2]));

    //     int maxi = 0;
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    int point = v[day][i] + dp[day - 1][i];
                    dp[day][last] = max(dp[day][last], point);
                }
                //                 dp[day][last] = maxi;
            }
        }
    }
    return dp[n - 1][3];
}