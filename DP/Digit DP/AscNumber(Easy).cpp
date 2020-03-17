#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
#define fast() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define digit(N) cout << fixed << setprecision((N))

int dp[1000000][10][2];

int main()
{

	int N;
	cin >> N;

	dp[0][0][0] = 1;

	for (int digit = 0; digit < N; digit++)
	{
		for (int last = 0; last < 10; last++)
		{
			for (int isless = 0; isless < 2; isless++)
			{
				for (int next = 0; next < 10; next++)
				{
					if (last <= next)
						(dp[digit + 1][next][isless] += dp[digit][last][isless]) %= mod;
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < 10; i++)
	{
		ans += dp[N][i][0] + dp[N][i][1];
		ans %= mod;
	}

	cout << ans << "\n";
}
