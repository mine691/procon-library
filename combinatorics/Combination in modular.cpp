#include <iostream>
#include <vector>
using namespace std;

const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
struct Combination
{
	using ll = int_fast64_t;

	int mod;
	vector<ll> mfact, rfact;

	Combination(int sz, int mod) : mfact(sz + 1), rfact(sz + 1), mod(mod)
	{
		mfact[0] = 1LL;
		for (int i = 1; i < sz + 1; i++)
		{
			mfact[i] = mfact[i - 1] * i % mod;
		}

		rfact[sz] = inv(mfact[sz]);

		for (int i = sz - 1; i >= 0; i--)
		{
			rfact[i] = rfact[i + 1] * (i + 1) % mod;
		}
	}

	ll fact(int k) const
	{
		return mfact[k];
	}

	ll pow(ll x, ll n) const
	{
		ll ret = 1LL;
		while (n > 0)
		{
			if (n & 1)
				(ret *= x) %= mod;
			(x *= x) %= mod, n >>= 1;
		}
		return ret;
	}

	ll inv(ll x) const
	{
		return pow(x, mod - 2);
	}

	ll Perm(int n, int r) const
	{
		if (r < 0 || n < r)
			return 0LL;
		return mfact[n] * rfact[n - r] % mod;
	}

	ll Binom(int p, int q) const
	{
		if (q < 0 || p < q)
			return 0LL;
		return mfact[p] * rfact[q] % mod * rfact[p - q] % mod;
	}
};

int main()
{
	int N = 1000;
	Combination comb(N, mod2);
	cout << comb.Binom(N, 100) << "\n";
}
