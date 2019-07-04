#include <vector>

template <typename T>
struct WeightedUnionFind
{
    vector<int> data;
    vector<T> weight_diff;

    WeightedUnionFind() {}

    WeightedUnionFind(int sz) : data(sz, -1), weight_diff(sz) {}

    int find(int k)
    {
        if (data[k] < 0)
            return k;
        weight_diff[k] += weight_diff[data[k]];
        auto par = find(data[k]);
        return data[k] = par;
    }

    T weight(int t)
    {
        find(t);
        return weight_diff[t];
    }

    bool unite(int x, int y, T w)
    {
        w += weight(x);
        w -= weight(y);
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (data[x] > data[y])
        {
            swap(x, y);
            w *= -1;
        }
        data[x] += data[y];
        data[y] = x;
        weight_diff[y] = w;
        return true;
    }

    T diff(int x, int y)
    {
        return weight(y) - weight(x);
    }

    bool same(int x, int y)
    {
        return (find(x) == find(y));
    }
};
