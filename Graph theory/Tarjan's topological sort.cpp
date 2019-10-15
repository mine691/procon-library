// Tarjan's algorithm
// G is a DAG.
void visit(const UnweightedGraph<int> &G, int u, vector<bool> &used, vector<int> &ans)
{
    if (used[u] == false)
    {
        used[u] = true;
        for (auto &v : G[u])
        {
            visit(G, v, used, ans);
        }
        ans.emplace_back(u);
    }
}

vector<int> topological_sort(const UnweightedGraph<int> &G)
{
    const int N = G.size();

    vector<bool> used(N, false);
    vector<int> ans;
    for (int u = 0; u < N; u++)
    {
        visit(G, u, used, ans);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
