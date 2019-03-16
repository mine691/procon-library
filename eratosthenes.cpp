vector<int> eratosthenes(int n)
{
    vector<int> res;
    vector<bool> prime(n + 1, 1);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (prime[i] == true)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        if (prime[i] == true)
            res.push_back(i);
    }
    return res;
}
