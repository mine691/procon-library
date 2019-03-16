/*
x^nのmodで割った余りを求める
計算量 𝑂(log 𝑁)
*/

using ll = long long;
ll mod_pow(ll x, ll n, ll mod)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            (res *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return res;
}
