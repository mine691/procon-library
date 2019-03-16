//どちらも𝑂(√𝑁)

//map型
#include <map>
template <typename T>
map<T, int> prime_factor(T n)
{
    map<T, int> res;
    for (T i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1)
        res[n]++; //nは素数
    return res;
}

//vactor型
#include <vector>
template <typename T>
vector<T> prime_factor(T n)
{
    vector<T> res;
    for (T i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1)
        res.push_back(n); //nは素数
    return res;
}
