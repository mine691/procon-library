#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>
#include <tuple>
using namespace std;

template <typename T>
struct edge
{
	int src, to;
	T cost;
	edge(int to, T cost) : src(-1), to(to), cost(cost) {}
	edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
	edge &operator=(const int &x)
	{
		to = x;
		return *this;
	}
	operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;

template <typename T>
using WeightedGraph = vector<Edges<T>>;

template <typename T>
vector<T> dijkstra(WeightedGraph<T> &g, int s)
{
	const auto INF = numeric_limits<T>::max();
	vector<T> dist(g.size(), INF);

	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
	dist[s] = 0;
	que.emplace(dist[s], s);
	while (que.empty() != true)
	{
		T cost;
		int idx;
		tie(cost, idx) = que.top();
		que.pop();
		if (dist[idx] < cost)
			continue;
		for (auto &e : g[idx])
		{
			auto next_cost = cost + e.cost;
			if (dist[e.to] <= next_cost)
				continue;
			dist[e.to] = next_cost;
			que.emplace(dist[e.to], e.to);
		}
	}
	dist.push_back(INF);
	return dist;
}

int main()
{
	int V, E, r;
	cin >> V >> E >> r;
	WeightedGraph<int> G(V);

	for (int i = 0; i < E; i++)
	{
		int s, t, d;
		cin >> s >> t >> d;
		G[s].emplace_back(t, d);
	}

	auto dist = dijkstra(G, r);

	for (int i = 0; i < V; i++)
	{
		if (dist[i] == dist[V])
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}
