#include <vector>

template <typename T>
struct BinaryIndexedTree
{
    vector<T> bit;

    BinaryIndexedTree(int sz)
    {
        bit.assign(sz++, 0);
    }

    T sum(int a)
    {
        T res = 0;
        for (int x = a + 1; x > 0; x -= x & -x)
            res += bit[x];
        return res;
    }

    void add(int a, T w)
    {
        for (int x = a + 1; x < bit.size(); x += x & -x)
            bit[x] += w;
    }

    T getSum(int a, int b)
    {
        if (a == 0)
            return sum(b);
        T p = sum(a - 1), q = sum(b);
        return q - p;
    }
};
