# bit DP とは
n 個の要素の順列としてありうるものの中から最適なものを求めたい

dp[S] := (集合が S の時の何かしらの値)

漸化式は

dp[S \ {i}] = dp[S] + cost(S, i)
(cost(S, i) は S に i を加えるときの cost)

S は n 個元集合を bit で表したもの

S \union {i} は S｜(1 << i)
S \ {i] は S & ~(1 << i) 
一般に、S, T が bit ｆで表せた集合のとき、
S \cup T は S & T
S \union T は S | T
となる。

# 巡回セールスマン問題
dp[S][v] := 最後に頂点 v に到達した時, {0,1,2,…,n-1} の部分集合 S を巡回する最短距離。

再帰で書くといい。

# 例題
https://yukicoder.me/problems/no/698 (https://yukicoder.me/submissions/494828)

