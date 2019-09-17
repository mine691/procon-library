/*
N以下の整数の素因数の個数のクエリを前計算O(NloglogN),クエリO(1)で求める
omegaを累積すると階乗や順列の場合も求められる
*/

ll f[5000010], omega[5000010];
int N = 5000001, Q;

void precalc()
{
    for (int i = 2; i < N; i++)
    {
        if (f[i] == 0)
        {
            for (int j = i; j < N; j += i)
            {
                f[j] = i;
            }
        }
    }
    for (int i = 2; i < N; i++)
    {
        omega[i] = omega[i / f[i]] + 1;
    }

    // factorial
    /* 
    for (int i = 0; i < N; i++)
    {
        omega[i + 1] += omega[i];
    }
    */
}

int count_factor_query(int a)
{
    return omega[a];
}
