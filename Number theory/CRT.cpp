template <typename T>
T extgcd(T a, T b, T &x, T &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    T d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

/*
given : modular equation x = b[i] over mod m[i]
return pair (r, m) s.t. x = r mod over m = lcm{m[i]}
if return is (0, -1) then there is no solution
*/
template <typename T>
pair<T, T> CRT(const vector<T> &b, const vector<T> &m)
{
    T r = 0, M = 1;
    int K = b.size();
    for (int i = 0; i < K; i++)
    {
        T p, q, d = extgcd(M, m[i], p, q);
        if (b[i] % d != r % d)
            return {0, -1};
        r += M * (((b[i] - r) / d * p) % m[i] / d);
        M *= m[i] / d;
    }
    return {(r % M + M) % M, M};
}
