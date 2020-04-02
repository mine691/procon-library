#include <bits/stdc++.h>
using namespace std;
using ll = int_fast64_t;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
#define fast() ios::sync_with_stdio(false), cin.tie(nullptr)
#define digit(N) cout << fixed << setprecision((N))
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using UnweightedGraph = vector<vector<int>>;

template <typename G>
struct LowestCommonAncestor
{
	const int log2_n;
	vector<int> depth;
	const G &g;
	vector<vector<int>> parent;

	LowestCommonAncestor(const G &g) : g(g), depth(g.size()), log2_n(32 - __builtin_clz(g.size()))
	{
		parent.assign(log2_n, vector<int>(g.size(), -1));
		build();
	}

	void dfs(int v, int p, int d)
	{
		parent[0][v] = p;
		depth[v] = d;
		for (auto &to : g[v])
		{
			if (to != p)
				dfs(to, v, d + 1);
		}
	}

	void build()
	{
		dfs(0, -1, 0);
		for (int k = 0; k + 1 < log2_n; k++)
		{
			for (int i = 0; i < parent[k].size(); i++)
			{
				if (parent[k][i] == -1)
					parent[k + 1][i] = -1;
				else
					parent[k + 1][i] = parent[k][parent[k][i]];
			}
		}
	}

	int LCA_query(int u, int v)
	{
		if (depth[u] > depth[v])
			swap(u, v);

		for (int i = log2_n - 1; i >= 0; i--)
		{
			if (((depth[v] - depth[u]) >> i) & 1)
				v = parent[i][v];
		}

		if (u == v)
			return u;

		for (int i = log2_n - 1; i >= 0; i--)
		{
			if (parent[i][u] != parent[i][v])
			{
				u = parent[i][u];
				v = parent[i][v];
			}
		}
		return parent[0][u];
	}
};

int main()
{
	fast();

	int N;
	cin >> N;

	UnweightedGraph G(N);
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}

	auto LCA = LowestCommonAncestor<UnweightedGraph>(G);
	auto dist = LCA.depth;

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		int c = LCA.LCA_query(a, b);

		cout << dist[a] + dist[b] - 2 * dist[c] + 1 << "\n";
	}
}
