/*
nCrの定義式から求める
計算量 各クエリに対して𝑂(log 𝑟)
*/

using ll = long long;
ll COM(ll n, ll k)
{
    if (k < 0 || n < k)
        return 0;
    ll ret = 1;
    for (ll i = 1; i <= k; ++i)
    {
        ret *= n--;
        ret /= i;
    }
    return ret;
}
