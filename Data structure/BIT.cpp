#include <vector>
// 1 - indexed
template <typename T>
struct BIT
{
    vector<T> bit;

    BIT(int sz) : bit(sz + 1, 0) {}

    T sum(int k)
    {
        T res = 0;
        for (int x = k + 1; x > 0; x -= x & -x)
            res += bit[x];
        return res;
    }

    void add(int k, T w)
    {
        for (int x = k + 1; x < bit.size(); x += x & -x)
            bit[x] += w;
    }

    // sum of [x, y)
    T getSum(int x, int y)
    {
        return sum(y - 1) - sum(x - 1);
    }
};
