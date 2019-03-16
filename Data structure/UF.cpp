/*
unite(x,y): 集合XとYを併合する. 併合済のときfalse,未併合のときtrueが返される
connected(x,y): 要素x,yが同じ集合に属するならtrue,そうでないならfalse
find(k): 要素kが属する集合を求める
size(k): 要素kが属する集合の要素の数を求める
各計算量 𝑂(α(𝑁))
*/
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
