// O(V + E) by Kosaraju's algorithm
using UnweightedGraph = vector<vector<int>>;

template <typename G>
struct Strongly_Connected_Components
{
    const G &g;

    UnweightedGraph dgraph, rev_dgraph;
    vector<int> comp, order, used;
    int sz = 0;

    Strongly_Connected_Components(G &g) : g(g), dgraph(g.size()), rev_dgraph(g.size()), comp(g.size(), -1), used(g.size())
    {
        for (int i = 0; i < g.size(); i++)
        {
            for (auto &e : g[i])
            {
                dgraph[i].emplace_back((int)e);
                rev_dgraph[(int)e].emplace_back(i);
            }
        }
    }

    int operator[](int k)
    {
        return comp[k];
    }

    void dfs(int idx)
    {
        if (used[idx])
            return;
        used[idx] = true;
        for (int &to : dgraph[idx])
            dfs(to);
        order.push_back(idx);
    }

    void rdfs(int idx, int cnt)
    {
        if (comp[idx] != -1)
            return;
        comp[idx] = cnt;
        for (int to : rev_dgraph[idx])
            rdfs(to, cnt);
    }

    void build(UnweightedGraph &t)
    {
        for (int i = 0; i < dgraph.size(); i++)
        {
            dfs(i);
        }
        reverse(begin(order), end(order));

        int ptr = 0;
        for (int i : order)
        {
            if (comp[i] == -1)
            {
                rdfs(i, ptr);
                ptr++;

                sz = max(sz, ptr);
            }
        }

        t.resize(ptr);

        for (int i = 0; i < g.size(); i++)
        {
            for (auto &to : g[i])
            {
                int x = comp[i], y = comp[to];
                if (x == y)
                    continue;

                t[x].push_back(y);
            }
        }
    }

    int DAG_size()
    {
        return sz;
    }
};
