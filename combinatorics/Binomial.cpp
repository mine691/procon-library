#include <iostream>
using namespace std;

using ll = int_fast64_t;
ll Binom(ll n, ll k)
{
	if (k < 0 || n < k)
		return 0;
	ll res = 1;
	for (ll i = 1; i <= k; ++i)
	{
		res *= n--;
		res /= i;
	}
	return res;
}

int main()
{
	cout << Binom(10, 5) << "\n";
}
