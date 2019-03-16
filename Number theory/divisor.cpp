#include <vector>
#include <algorithm>
template <typename T>
vector<T> divisor(T n)
{
    vector<T> divisor;
    for (T i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisor.push_back(i);
            if (i * i != n)
                divisor.push_back(n / i);
        }
    }
    sort(divisor.begin(), divisor.end());
    return divisor;
}
