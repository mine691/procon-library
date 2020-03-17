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

・[yukicoder No.741 AscNumber(Easy)](https://yukicoder.me/problems/no/741)
dp[dgt][last][isless] := 上位dgt桁目まで確定していて、最後の文字がlastで、10^N-1未満かどうかがislessである場合の数  
islessはいらないが、桁DPであることを意識するためにつけた。[AC code](https://yukicoder.me/submissions/445173)  

・[Codeforces Round #549 B. Nirvana](https://codeforces.com/contest/1143/problem/B)  
dp[digit][isless] := 上位digit桁目まで決まっていて、N未満かどうかがislessであるときの最大値  
初期条件に注意する。([AC code](https://codeforces.com/contest/1143/submission/73497777))

# To do
https://codeforces.com/problemset/problem/1245/F  
https://codeforces.com/problemset/problem/1036/C  
https://atcoder.jp/contests/abc129/tasks/abc129_e  
https://codeforces.com/contest/914/problem/C
