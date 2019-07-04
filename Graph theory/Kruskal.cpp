#include <algorithm>
#include <vector>

template <typename T>
T Kruskal(Edges<T> &edges, int V)
{
    sort(edges.begin(), edges.end(), [](const edge<T> &a, const edge<T> &b) { return a.cost < b.cost; });
    UnionFind uf(V);
    T res = 0;
    for (auto &e : edges)
    {
        if (uf.unite(e.src, e.to) == true)
            res += e.cost;
    }
    return res;
}
