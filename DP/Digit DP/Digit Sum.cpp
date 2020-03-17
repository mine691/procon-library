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
dp[dgt][d][isless] := 上位dgt桁目まで確定して各桁の数字の総和modDがdであり、K未満かどうかがislessである場合の数
*/

int dp[10101][111][2];

int main()
{
	string K;
	cin >> K;
	int D, N = K.size();
	cin >> D;

	dp[0][0][0] = 1;

	for (int digit = 0; digit < N; digit++) // 桁数
	{
		for (int d = 0; d < D; d++) // 総和 mod D
		{
			int c = K[digit] - '0';
			for (int isless = 0; isless < 2; isless++) // K 未満であるか (isless = true -> K 未満)
			{
				for (int next = 0; next < 10; next++) // digit 桁目にくる数字
				{
					if (c > next) // 上位の状態に依らずisless = trueになる
					{
						(dp[digit + 1][(d + next) % D][1] += dp[digit][d][isless]) %= mod;
					}
					if (c == next) // isless = false -> Kと同じ, isless = true -> 既にK以下
					{
						(dp[digit + 1][(d + next) % D][isless] += dp[digit][d][isless]) %= mod;
					}
					if (c < next) // isless = false だとnextは置けない(Kより大きくなる)
					{
						if (isless)
							(dp[digit + 1][(d + next) % D][isless] += dp[digit][d][isless]) %= mod;
					}
				}
			}
		}
	}
	int ans = (dp[N][0][1] + dp[N][0][0] - 1 + mod) % mod; // 0が含まれているので-1をする
	cout << ans << "\n";
}
