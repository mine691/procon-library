using ll = long long;
ll comb(ll n, ll k)
{
    if (k < 0 || n < k)
        return 0;
    ll res = 1;
    for (ll i = 1; i <= k; ++i)
    {
        res *= n--;
        res /= i;
    }
    return res;
}
