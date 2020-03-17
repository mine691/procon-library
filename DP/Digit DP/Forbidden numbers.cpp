#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
#define fast() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define digit(N) cout << fixed << setprecision((N))

#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

/*
dp[dgt][d][isless] := 上位dgt桁目まで確定していて、4または9を含むかのフラグがdで、K未満かどうかがislessである場合の数
*/

ll digit_dp(string s)
{
	int N = s.size();

	vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(2, vector<ll>(2)));

	dp[0][0][0] = 1;

	for (int digit = 0; digit < N; digit++)
	{
		int c = s[digit] - '0';

		for (int contain = 0; contain < 2; contain++)
		{

			for (int isless = 0; isless < 2; isless++)
			{

				for (int d = 0; d <= (isless ? 9 : c); d++)
				{
					dp[digit + 1][contain || d == 4 || d == 9][isless || (d < c)] += dp[digit][contain][isless];
				}
			}
		}
	}

	return dp[N][1][0] + dp[N][1][1];
}

int main()
{
	ll A, B;
	cin >> A >> B;

	cout << digit_dp(to_string(B)) - digit_dp(to_string(A - 1)) << "\n";
}
