// 分散の計算
double sum(double data[], int n)
{
    double total = 0.0, N = n * 1.;
    for (int i = 0; i < n; i++)
    {
        total += data[i];
    }
    double a = total / n;
    double v = 0.0;
    for (int i = 0; i < n; i++)
        v += (data[i] - a) * (data[i] - a);
    return v / N;
}
