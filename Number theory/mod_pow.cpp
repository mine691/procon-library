using ll = long long;
const ll mod = 1e9 + 7;
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
