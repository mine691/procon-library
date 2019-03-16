/*
pascalの三角形を求める
計算量は 𝑂(𝑁𝑟),見積もりとしては𝑂(𝑁²) 
N<3000くらいならOK
*/

#include <vector>
using ll = long long;
vector<vector<ll>> get_combination(int N)
{
    vector<vector<ll>> pascal(N + 1, vector<ll>(N + 1));
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                pascal[i][j] = 1;
            else
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }
}
