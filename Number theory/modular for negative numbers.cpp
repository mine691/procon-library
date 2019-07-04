const int MOD = 1000000007;

template <typename T>
T mod(T val, T m)
{
    return val % m + (val % m < 0 ? m : 0);
}
