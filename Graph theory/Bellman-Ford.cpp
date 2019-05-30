struct edge
{
    int to, cost;
};

template <typename T>
using Edges = vector<edge<T>>;

template <typename T>
vector<T> BellmanFord(Edges<T> &edges, int N, int start)
{
    ll INF = 1e18;
    vector<T> dist(N, INF);
    dist[start] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (auto &e : edges)
        {
            if (dist[e.scr] == INF)
                continue;
            dist[e.to] = min(dist[e.to], dist[e.scr] + e.cost);
        }
    }
    for (auto &e : edges)
    {
        if (dist[e.scr] == INF)
            continue;
        if (dist[e.scr] + e.cost < dist[e.to])
            return vector<T>();
    }
    return dist;
}
