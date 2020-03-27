using ll = long long;
// maybeO(log^6 p)
template <typename T>
T gcd(T a, T b)
{
	return (b ? gcd(b, a % b) : a);
}

ll powmod(ll a, ll b, ll p)
{
	ll res = 1;
	while (b)
		if (b & 1)
			res = ll(res * 1ll * a % p), --b;
		else
			a = ll(a * 1ll * a % p), b >>= 1;
	return res;
}

ll generator(ll p)
{
	vector<ll> fact;
	ll phi = p - 1, n = phi;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
		{
			fact.push_back(i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back(n);

	for (int res = 2; res <= p; ++res)
	{
		bool ok = true;
		for (size_t i = 0; i < fact.size() && ok; ++i)
			ok &= powmod(res, phi / fact[i], p) != 1;
		if (ok)
			return res;
	}
	return -1;
}
