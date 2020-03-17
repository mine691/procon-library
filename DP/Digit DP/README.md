# 桁DPとは
「整数K以下の整数であって、条件(P)を満たすものの個数を求めよ」という問題をDPで解く手法のこと。  
s = Kとし、DP配列を  
dp[i][j][isless] := 上からi桁まで見たとき状態jであって、Kと比べてislessである  
と宣言する。  
遷移に癖があるので、詳細はコードを参照してほしい。

# 例
・[EDPC-S Digit Sum](https://atcoder.jp/contests/dp/tasks/dp_s)  
1以上K以下の整数のうち、各桁の総和がDの倍数であるようなものの個数を求める。  
状態として「総和 mod D」を持つと、O(N log K)でできる。(桁数をNとすればO(NK))  

・[AC ABC007-D 禁止された数字](https://atcoder.jp/contests/abc007/tasks/abc007_4)  
dp[dgt][d][isless] := 上位dgt桁目まで確定していて、4または9を含むかのフラグがdで、K未満かどうかがislessである場合の数
