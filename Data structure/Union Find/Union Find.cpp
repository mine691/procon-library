#include <iostream>
#include <vector>
using namespace std;

// 0-indexed
struct UnionFind
{
	vector<int> data, pointer;
	int component;

	UnionFind(int sz)
	{
		data.assign(sz, -1);
		pointer.assign(sz, 0);

		for (int i = 0; i < sz; i++)
		{
			pointer[i] = i;
		}

		component = sz;
	}

	bool unite(int x, int y)
	{
		x = root(x), y = root(y);
		if (x == y)
			return false;
		if (data[x] > data[y])
			swap(x, y);
		swap(pointer[x], pointer[y]);
		component--;
		data[x] += data[y];
		data[y] = x;
		return true;
	}

	int root(int k)
	{
		if (data[k] < 0)
			return k;
		data[k] = root(data[k]);
		return data[k];
	}

	int size(int k)
	{
		return (-data[root(k)]);
	}

	bool same(int x, int y)
	{
		return (root(x) == root(y));
	}

	int connected_component()
	{
		return component;
	}

	vector<int> get_set(int x)
	{
		vector<int> res;
		int y = x;
		res.push_back(x);
		while (pointer[y] != x)
		{
			y = pointer[y];
			res.push_back(y);
		}

		return res;
	}
};

int main()
{
	int N, M, ans = 0;
	cin >> N >> M;
	UnionFind uf(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		uf.unite(a, b);
	}
}
