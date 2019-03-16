int ok = 1000; //解が存在する値
int ng = -1;   //解が存在しない値

while (abs(ok - ng) > 1)
{
    int mid = (ok + ng) / 2;
    if (solve(mid))
        ok = mid;
    else
        ng = mid;
}

//x以上となる最小のindexを取得
auto s_ind = distance(s.begin(), lower_bound(s.begin(), s.end(), x));
