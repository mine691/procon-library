
#include <vector>

struct UnionFind
{
    vector<int> data;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
    }

    bool unite(int x, int y)
    {
        x = root(x), y = root(y);
        if (x == y)
            return false;
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int root(int k)
    {
        if (data[k] < 0)
            return k;
        data[k] = root(data[k]);
        return data[k];
    }

    int size(int k)
    {
        return (-data[root(k)]);
    }

    bool same(int x, int y)
    {
        return (root(x) == root(y));
    }
};
