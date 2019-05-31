#include <vector>
const long long mod = 1e9 + 7;
//a partition of n by k-th numbers

template <typename T>
vector<vector<T>> get_partition(int n, int k)
{
    vector<vector<T>> dp(n + 1, vector<T>(k + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (i - j >= 0)
                dp[i][j] += dp[i - j][j];
            dp[i][j] %= mod;
        }
    }
    return dp;
}
