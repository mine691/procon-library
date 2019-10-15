// Kahn's algorithm
// G is a DAG.
vector<int> topological_sort(const UnweightedGraph<int> &G)
{
    const int N = G.size();
    vector<int> indegree(N, 0);
    stack<int> st; // set of vertex whose indegree is zero.

    for (auto &source : G)
    {
        for (auto &to : source)
        {
            indegree[to]++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
            st.push(i);
    }

    vector<int> ans;
    while (st.size() > 0)
    {
        int u = st.top();
        st.pop();
        ans.push_back(u);
        for (auto &v : G[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                st.push(v);
        }
    }

    return ans;
}
