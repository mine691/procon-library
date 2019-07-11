// check existence of intersection at the lines
bool intersect(const Line &L1, const Line &L2)
{
    // non-parallel || same line
    bool r = (abs(cross(L1.b - L1.a, L2.b - L2.a)) < EPS) || (abs(cross(L1.b - L1.a, L2.a - L1.a)) < EPS);
    return r;
}

// check existence of intersection at the segments
bool intersect(const Segment &s, const Segment &t)
{
    bool r = ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
    return r;
}

bool intersect(const Line &l, const Point &p)
{
    return abs(ccw(l.a, l.b, p)) != 1;
}

bool intersect(const Segment &s, const Point &p)
{
    return ccw(s.a, s.b, p) == 0;
}

bool intersect(const Line &l, const Segment &s)
{
    return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}
