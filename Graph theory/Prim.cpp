#include <vector>
#include <utility>
#include <queue>

template <typename T>
T Prim(WeightedGraph<T> &g)
{
    T res = 0;
    vector<bool> used(g.size(), false);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
    que.emplace(0, 0);
    while (que.empty() != true)
    {
        auto p = que.top();
        que.pop();
        if (used[p.second] == true)
            continue;
        used[p.second] = true;
        res += p.first;
        for (auto &e : g[p.second])
        {
            que.emplace(e.cost, e.to);
        }
    }
    return res;
}
