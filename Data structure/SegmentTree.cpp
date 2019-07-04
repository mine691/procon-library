// 0 - indexed
template <typename Monoid>
struct Segmenttree
{
    using F = function<Monoid(Monoid, Monoid)>;
    const Monoid e;
    const F f;

    int sz;
    vector<Monoid> seg;

    // size, operator, unit
    Segmenttree(int N, const F f, const Monoid e) : f(f), e(e)
    {
        sz = 1;
        while (sz < N)
            sz *= 2;
        seg.assign(2 * sz - 1, e);
    }

    void set(int k, const Monoid &x) { seg[k + sz] = x; }
    void build()
    {
        for (int k = sz - 1; k > 0; k--)
        {
            seg[k] = f(seg[2 * k + 1], seg[2 * k + 2]);
        }
    }
    void update(int k, const Monoid &x)
    {
        k += sz - 1;
        seg[k] = x;
        while (k > 0)
        {
            k = (k - 1) / 2;
            seg[k] = f(seg[k * 2 + 1], seg[k * 2 + 2]);
        }
    }

    Monoid sub_query(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
            return e;

        if (a <= l && r <= b)
            return seg[k];
        else
        {
            Monoid vl = sub_query(a, b, k * 2 + 1, l, (l + r) / 2);
            Monoid vr = sub_query(a, b, k * 2 + 2, (l + r) / 2, r);
            return f(vl, vr);
        }
    }

    // [l, r)
    Monoid query(int l, int r)
    {
        return sub_query(l, r, 0, 0, sz);
    }

    Monoid operator[](const int &k) const
    {
        return seg[k + sz];
    }
};