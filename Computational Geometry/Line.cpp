// a line given two points
struct Line
{
    Point a, b;
    Line() = default;

    Line(Point a, Point b) : a(a), b(b) {}

    // Ax + By = C
    Line(Real A, Real B, Real C)
    {
        if (eq(A, 0))
            a = Point(0, C / B), b = Point(1, C / B);
        else if (eq(B, 0))
            b = Point(C / A, 0), b = Point(C / A, 1);
        else
            a = Point(0, C / B), b = Point(C / A, 0);
    }

    friend istream &operator>>(istream &is, Line &a)
    {
        return is >> a.a >> a.b;
    }

    friend ostream &operator<<(ostream &os, Line &p)
    {
        return os << p.a << " to " << p.b;
    }
};

using Lines = vector<Line>;

//For given three points p1,p2,p, find the projection point x of p onto p1p2.
Point projection(const Line &l, const Point &p)
{
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b); // direction vector
    return l.a + (l.a - l.b) * t;
}

//For given three points p1,p2,p, find the reflection point x of p onto p1p2.
Point reflection(const Line &l, const Point &p)
{
    return p + (projection(l, p) - p) * 2.0;
}

// Counter_Clockwise, a is standard point
int ccw(const Point &a, Point b, Point c)
{
    b = b - a, c = c - a;
    if (cross(b, c) > EPS)
        return +1; // counter clockwise
    if (cross(b, c) < -EPS)
        return -1; // clockwise
    if (dot(b, c) < 0)
        return +2; // c--a--b on line
    if (norm(b) < norm(c))
        return -2; // a--b--c on line
    return 0;      // c on segment a-b
}

// two lines are parallel
bool Parallel(const Line &L1, const Line &L2)
{
    return eq(cross(L1.b - L1.a, L2.b - L2.a), 0.0);
}

// two lines are orthogonal
bool Orthogonal(const Line &L1, const Line &L2)
{
    return eq(dot(L1.b - L1.a, L2.b - L2.a), 0.0);
}

// cross point of two lines
Point CrossPoint(const Line &L1, const Line &L2)
{
    Real A = cross(L1.b - L1.a, L2.b - L2.a);
    Real B = cross(L1.b - L1.a, L1.b - L2.a);
    if (abs(A) < EPS && abs(B) < EPS)
        return L1.a; // same line
    if (abs(A) < EPS)
        assert(false); // precondition !!!
    return L2.a + B / A * (L2.b - L2.a);
}
