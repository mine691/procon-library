#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

ll pow_mod(ll x, ll N, ll M) // return x^N mod M
{
	ll res = 1LL;
	while (N > 0)
	{
		if (N & 1)
			(res *= x) %= M;
		(x *= x) %= M, N >>= 1;
	}
	return res;
}

bool check(ll a, int s, ll d, ll N)
{
	ll x = pow_mod(a, d, N);
	if (x == 1)
		return true;

	for (int r = 0; r < s; r++)
	{
		if (x == N - 1)
			return true;
		x = x * x % N;
	}

	return false;
}

bool is_prime(ll N)
{
	if (N <= 1 || (N > 2 && N % 2 == 0))
		return false;

	ll d = N - 1, s = 0;
	while (!(d & 1))
		d >>= 1, ++s;

	vector<vector<ll>> test = {{2, 7, 61}, {2, 3, 5, 7, 11, 13, 17, 19, 23}};
	bool type = (N > 4759123140);

	for (int i = 0; test[type][i] < N && i < test[type].size(); i++)
	{
		if (!check(test[type][i], s, d, N))
			return false;
	}

	return true;
}

int main()
{
	ll N;
	cin >> N;

	cout << (is_prime(N) ? "Prime\n" : "Composite\n");
}
