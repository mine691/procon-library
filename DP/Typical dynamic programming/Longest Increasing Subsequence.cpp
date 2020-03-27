ll LIS(const vector<ll> &a)
{
	int N = a.size();

	vector<ll> dp(N, infll); // dp[i] := 長さが i + 1であるLISのうち、末尾の要素の最小値

	for (int i = 0; i < N; i++)
	{
		auto itr = lower_bound(dp.begin(), dp.end(), a[i]);

		*itr = a[i];
	}

	return lower_bound(dp.begin(), dp.end(), infll) - dp.begin();
}
