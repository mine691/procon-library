#include <iostream>
#include <vector>
using namespace std;

// 1 - indexed
template <typename T>
struct BIT
{
	vector<T> bit;

	BIT(int sz) : bit(sz + 1, 0) {}

	// sum of [1, k]
	T sum(int k)
	{
		T res = 0;
		for (int x = k; x > 0; x -= x & -x)
			res += bit[x];
		return res;
	}

	void add(int k, T w)
	{
		for (int x = k; x < bit.size(); x += x & -x)
			bit[x] += w;
	}

	// sum of [x, y)
	T getSum(int x, int y)
	{
		return sum(y - 1) - sum(x - 1);
	}

	// find an index i s.t. a[1] + a[2] + ⋯ + a[x] ≧ w
	T lower_bound(T w)
	{
		if (w <= 0)
			return 0;

		T x = 0;
		int p = 1, N = bit.size();

		while (2 * p <= N)
			p *= 2;

		for (T k = p; k > 0; k /= 2)
		{
			if (x + k <= N && bit[x + k] < w)
			{
				w -= bit[x + k];
				x += k;
			}
		}

		return x + 1;
	}
};

using ll = long long;
// p : permutation
ll inversion(vector<int> &p)
{
	int N = p.size();

	BIT<int> bit(N + 1);
	ll inv = 0;
	for (int i = 0; i < N; i++)
	{
		inv += bit.getSum(p[i], N + 1);
		bit.add(p[i], 1);
	}
	return inv;
}

int main()
{
	int N, Q;
	cin >> N >> Q;

	BIT<int> bit(N);
	while (Q--)
	{
		int com, x, y;
		cin >> com >> x >> y;
		if (com == 0)
		{
			bit.add(x, y);
		}
		if (com == 1)
		{
			cout << bit.getSum(x, y + 1) << "\n";
		}
	}
}
