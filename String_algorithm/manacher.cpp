vector<int> manacher(const string &s)
{
    // i : index, r : radius from i
    int N = s.size(), i = 0, r = 0;
    vector<int> radius(N);
    while (i < N)
    {
        while (i - r >= 0 && i + r < N && s[i - r] == s[i + r])
        {
            r++;
        }
        radius[i] = r;
        int k = 1;
        while (i - k >= 0 && i + k < N && k + radius[i - k] < r)
        {
            radius[i + k] = radius[i - k];
            k++;
        }
        i += k, r -= k;
    }
    return radius;
}
