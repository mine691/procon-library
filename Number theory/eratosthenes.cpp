vector<int> eratosthenes(int N)
{
    vector<int> res;
    vector<bool> prime(N + 1, 1);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; ++i)
    {
        if (prime[i] == true)
        {
            for (int j = 2 * i; j <= N; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (int i = 0; i <= N; ++i)
    {
        if (prime[i] == true)
            res.push_back(i);
    }
    return res;
}
