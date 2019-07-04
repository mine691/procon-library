//need UnionFind

struct BipartiteGraph : UnionFind
{
    vector<int> color;

    BipartiteGraph(int N) : color(2 * N, -1), UnionFind(2 * N) {}

    /*
    color u, v by same color ->  unite(u, v) && unite(u + N, v + N)
    color u, v by different color -> unite(u + N, v) && unite(u, v + N)
    */

    bool BG_unite(int u, int v, bool same)
    {
        int N = ((int)color.size()) / 2;
        if (same == true)
        {
            unite(u, v);
            unite(u + N, v + N);
        }
        else
        {
            unite(u + N, v);
            unite(u, v + N);
        }
    }

    // 0, 1, ..., v - 1 -> left; v, v + 1, ..., 2 * v - 1 -> right;
    bool BG_coloring()
    {
        int N = ((int)color.size()) / 2;
        for (int i = 0; i < N; i++)
        {
            int s = root(i), t = root(i + N);
            if (s == t)
                return false;
            if (color[s] < 0)
                color[s] = 0, color[t] = 1;
        }
        return true;
    }

    //return k's color
    bool operator[](int v)
    {
        return (bool)(color[root(v)]);
    }
};
