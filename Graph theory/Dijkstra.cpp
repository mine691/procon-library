#include <vector>
#include <utility>
#include <queue>
#include <limits>
#include <tuple>

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
