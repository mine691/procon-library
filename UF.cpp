#include <vector>

template <typename T>
struct UnionFind
{
    vector<T> data;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
    }

    bool connected(T x, T y)
    {
        return (find(x) == find(y));
    }

    bool unite(T x, T y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(T k)
    {
        if (data[k] < 0)
            return k;
        return (data[k] = find(data[k]));
    }

    int size(T k)
    {
        return (-data[find(k)]);
    }
};
