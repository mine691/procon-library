# やること
概要を書く  
非再帰セグ木にする  
遅延セグ木を書く　　
2Dセグ木を書く  

問題を解く  

# 概要
Segment Tree (以下、セグ木)とは一点更新区間取得ができるデータ構造である  
Segment_tree<type> 変数名(size, function, unit) で宣言できる  
function はモノイドの演算であり unit はモノイドの単位元である

# 関数
N はもとの列の長さ  
| 名前 | 説明 | 計算量 |
|:----------:|:-----------:|:------------:|
| set(int k, Monoid x) | build前のセグ木のk番目に値を入れる | O(1) |
| build() | セグ木をbuildする | O(N) |
| update(int k, Monoid x) | セグ木のk番目をxに更新する | O(log N) |
| add(int k, Monoid x) | セグ木のk番目の値にmonoid演算でxを作用させる | O(log N) |
| query(int l, int r) | 区間[l, r)クエリを返す | O(log N) |
| perator[int k] | k番目の値にアクセスする | O(1) |


# 例
https://codeforces.com/contest/1253/problem/D  
https://codeforces.com/contest/500/problem/B  
https://codeforces.com/contest/25/problem/D  
https://atcoder.jp/contests/abc157/tasks/abc157_d  
https://codeforces.com/contest/1012/problem/B  
https://codeforces.com/contest/1209/problem/D  
https://atcoder.jp/contests/abc120/tasks/abc120_d  
https://atcoder.jp/contests/abc126/tasks/abc126_e
