// g = gcd(a, b)
// (x, y) satisfies ax + by = gcd(a, b)
template <typename T>
T extgcd(T a, T b, T &x, T &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    T d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
