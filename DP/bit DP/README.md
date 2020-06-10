# bit DP とは
n 個の要素の順列としてありうるものの中から最適なものを求めたい

$$ dp[S] := (集合が S の時の何かしらの値) $$

dp[S \

S は n 個元集合を bit で表したもの

S \union {i} は S｜(1 << i)
S \ {i] は S & ~(1 << i) 
一般に、S, T が bit ｆで表せた集合のとき、
S \cup T は S & T
S \union T は S | T
となる。
