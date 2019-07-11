Real distance(const Point &a, const Point &b)
{
    return abs(a - b);
}

Real distance(const Line &L, const Point &p)
{
    return abs(p - projection(L, p));
}

Real distance(const Line &L1, const Line &L2)
{
    return intersect(L1, L2) ? 0 : distance(L1, L2.a);
}

Real distance(const Segment &s, const Point &p)
{
    Point r = projection(s, p);
    if (intersect(s, r))
        return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}

Real distance(const Segment &a, const Segment &b)
{
    if (intersect(a, b))
        return 0;
    return min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}
