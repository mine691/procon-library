#include <vector>
#include <limits>

//G[i][i] = 0 ; if G[i][i] < 0 -> G has negative cycles
void Warshall_Floyd(Matrix<ll> &g)
{
    ll INF = numeric_limits<ll>::max();
    int N = g.size();
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (g[i][k] == INF || g[k][j] == INF)
                    continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}
