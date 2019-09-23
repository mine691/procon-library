using Real = double;
using Point = complex<Real>;
const Real Pi = acos(-1), EPS = 1e-9;
inline bool eq(Real a, Real b) { return fabs(a - b) < EPS; }

//scalar
Point operator*(const Point &p, const Real &c)
{
    return Point(c * real(p), c * imag(p));
}

//add
Point operator+(const Point &p, const Point &q)
{
    return Point(real(p) + real(q), imag(p) + imag(q));
}

Point operator-(const Point &p, const Point &q)
{
    return Point(real(p) - real(q), imag(p) - imag(q));
}

//equal
bool operator==(const Point &p, const Point &q)
{
    return (real(p) == real(q)) && (imag(p) == imag(q));
}

Real radian_to_degree(Real r)
{
    return (r * 180.0 / Pi);
}

Real degree_to_radian(Real d)
{
    return (d * Pi / 180.0);
}

//rotate
Point rot(Real theta, const Point &p)
{
    return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag());
}

// norm
Real norm(const Point &p)
{
    return (real(p) * real(p) + imag(p) * imag(p));
}

Real abs(const Point &p)
{
    return sqrt(norm(p));
}

//argumant [0, 2 * Pi)
Real arg(const Point &p)
{
    Real a = atan2(imag(p), real(p));
    if (a < 0)
        a = fabs(a) + Pi;
    return a;
}

Real dot(const Point &p, const Point &q)
{
    return (real(p) * real(q) + imag(p) * imag(q));
}

// regard z - component is zero
Real cross(const Point &p, const Point &q)
{
    return real(p) * imag(q) - imag(p) * real(q);
}

//input
istream &operator>>(istream &is, Point &p)
{
    Real a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
}

//output
ostream &operator<<(ostream &os, Point &p)
{
    os << fixed << setprecision(10) << p.real() << " " << p.imag();
}

//get angle of two vectors (radian)
Real get_angle(Point a, Point b){
    return acos(dot(a, b) / (abs(a) * abs(b)));
}

using Points = vector<Point>;
