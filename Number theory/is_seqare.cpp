using ll = long long;
bool is_seqare(ll N)
{
    ll ok = -1, ng = 1e7;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (mid * mid <= N)
            ok = mid;
        else
            ng = mid;
    }
    if (ok * ok == N)
        return true;
    else
        return false;
}
