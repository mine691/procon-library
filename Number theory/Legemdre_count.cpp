// get the exponent of the largest power of a prime p that divides the factorial n!
template <typename T>
T Legendre_count(T N, T p)
{
    T res = 0;
    while (p <= N)
    {
        res += N / p;
        N /= p;
    }
    return res;
}
