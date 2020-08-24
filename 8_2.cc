#include <bits/stdc++.h>
using namespace std;
//return maximum number of tiles that can be added inside 3xN matrix.
//Size of tile could be vertical 2x1 or horizontal 1x2
int max_2x1_1x2TilesIn_3Rows_NColumns(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1; //1 tile placed vertically
    if (n == 2)
        return 3; //3 tiles placed horizontally
    if (n == 3)
        return 4; //3 tiles placed horizontally and 1 vertically
    return max_2x1_1x2TilesIn_3Rows_NColumns(n - 1) + max_2x1_1x2TilesIn_3Rows_NColumns(n - 2) + max_2x1_1x2TilesIn_3Rows_NColumns(n - 3);
}
int memo_helper(vector<int> &memo, int n)
{
    if (n < 0)
        return -1;
    if (memo[n] == -1)
    {
        memo[n] = memo_helper(memo, n - 1) + memo_helper(memo, n - 2) + memo_helper(memo, n - 3);
    }
    return memo[n];
}
//Using Memoization
int Memo_max_2x1_1x2TilesIn_3Rows_NColumns(int n)
{
    vector<int> memo(n + 1, -1);
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 3;
    memo[3] = 4;
    memo_helper(memo, n);
    return memo[n];
}
//DP bottom up
int DP_max_2x1_1x2TilesIn_3Rows_NColumns(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 4;
    if (n > 3)
    {
        int prev = 3, prev_prev = 2, prev_prev_prev = 1;
        for (int i = 4; i <= n; ++i, ++prev, ++prev_prev, ++prev_prev_prev)
        {
            dp[i] = dp[prev] + dp[prev_prev] + dp[prev_prev_prev];
        }
    }
    return dp[n];
}
int main(int argc, char const *argv[])
{
    int n = 20;
    for (int i = 0; i <= n; ++i)
        cout << "n : " << i << ": " << max_2x1_1x2TilesIn_3Rows_NColumns(i) << endl;
    cout << "\n";
    for (int i = 0; i <= n; ++i)
        cout << "n : " << i << ": " << Memo_max_2x1_1x2TilesIn_3Rows_NColumns(i) << endl;
    cout << "\n";
    for (int i = 0; i <= n; ++i)
        cout << "n : " << i << ": " << DP_max_2x1_1x2TilesIn_3Rows_NColumns(i) << endl;
    return 0;
}