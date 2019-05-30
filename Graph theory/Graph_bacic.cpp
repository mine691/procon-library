template <typename T>
struct edge
{
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

//Weighted edge set
template <typename T>
using Edges = vector<edge<T>>;

//Weighted graph
template <typename T>
using WeightedGraph = vector<Edges<T>>;

//Unweighted graph (adjacency matrix)
//Initialize : vector<vector<int>>(N, vector<int>(N, 0))
template <typename T>
using UnweightedGraph = vector<vector<T>>;

//distance matrix
template <typename T>
using Matrix = vector<vector<T>>;
