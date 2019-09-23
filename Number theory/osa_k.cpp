// for query

// init table
vector<int> sieve(int N)
{
    vector<int> res(N + 1);

    for (int i = 2; i <= N; i++)
    {
        if (res[i] == 0)
        {
            for (int j = i; j <= N; j += i)
            {
                if (res[j] == 0)
                    res[j] = i;
            }
        }
    }
    return res;
}

// 素因数分解 O(log N)
vector<int> prime_factor(int N, const vector<int> &min_factor)
{
    // min_factor is vector which got by sieve()
    vector<int> res;
    while (N > 1)
    {
        res.push_back(min_factor[N]);
        N /= min_factor[N];
    }
    return res;
}

bool is_prime(int N, const vector<int> &min_factor)
{
    return min_factor[N] == N;
}
