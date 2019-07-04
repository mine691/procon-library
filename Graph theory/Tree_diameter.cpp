template <typename T>
pair<T, int> dfs(const WeightedGraph<T> &G, int v, int par)
{
    pair<T, int> res = {0, v};
    for (auto &e : G[v])
    {
        if (e.to == par)
            continue;
        auto dist = dfs(G, e.to, v);
        dist.first += e.cost;
        res = max(res, dist);
    }
    return res;
}

template <typename T>
T tree_diameter(const WeightedGraph<T> &G)
{
    auto p = dfs(G, 0, -1);
    auto q = dfs(G, p.second, -1);
    return q.first;
}
