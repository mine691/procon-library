// map
template <typename T>
map<T, int> prime_factor(T n)
{
    map<T, int> res;
    for (T i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1)
        res[n]++;
    return res;
}

// vector
template <typename T>
vector<T> prime_factor(T n)
{
    vector<T> res;
    for (T i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1)
        res.push_back(n);
    return res;
}

//N以下の数について、それぞれの素因数を重複を除いて求める
vector<vector<int>> prime_factor_lists(int N)
{
    vector<vector<int>> prime_lists(N + 1);
    for (int i = 2; i <= N; i++)
    {
        if (prime_lists[i].size() == 0)
        {
            for (int j = i; j <= N; j += i)
            {
                prime_lists[j].push_back(i);
            }
        }
    }
    return prime_lists;
}

// for query using osa_k way

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

// prime factorization O(log N)
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
