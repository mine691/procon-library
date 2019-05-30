template <typename T>
vector<T> BellmanFrod(Edges<T> &edges, int N, int source)
{
    const auto INF = numeric_limits<T>::max();
    vector<T> dist(N, INF); //distance from source
    dist[source] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (auto &e : edges)
        {
            if (dist[e.src] == INF)
                continue;
            dist[e.to] = min(dist[e.to], dist[e.src] + e.cost);
        }
    }

    // check for negative-weight cycles
    for (auto &e : edges)
    {
        if (dist[e.src] == INF)
            continue;
        if (dist[e.src] + e.cost < dist[e.to])
            return vector<T>();
    }
    return dist;
}
