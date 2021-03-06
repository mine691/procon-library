# 概要
Binary Indexed Tree(Fenwick Treeとも言われている,以下BIT)は、数列に対して以下の二種類にクエリを高速に扱うデータ構造である。  
・一点加算  
・区間和  
BITの特徴として、実装が楽で省メモリなことが挙げられる。また、本実装は1-indexedであることに注意する。
# 関数
BITの長さをNとする。宣言時は全ての要素が0で初期化されている。  
lower_boundは負の要素があると上手く作動しない。  
| 名前 | 説明 | 計算量 |
|:----------:|:-----------:|:------------:|
| sum(int k) | 閉区間[1,K]の和を返す | O(log N) |
| add(int k, T w) | 第k項にwを加える　| O(log N) |
| getSum(int x, int y) | 半開区間[x,y)の和を返す | O(log N) |
| inversion(vector<int> p) | 順列pの転倒数を返す | O(log N) |
| lower_bound(T x) | 和がx以上となる最小のindexを返す | O(log N) |

# 例
・[AOJ DSL_2_B Range Sum Query](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B)  
そのままの関数を使えばいい

・[Codeforces Round #590 D.Distinct Characters Queries](https://codeforces.com/contest/1234/problem/D)  
文字列sに対して、以下のクエリが与えられる。  
1: pos c (set s[pos] := c)  
2: l r (s[l;r]に含まれる異なる文字列の個数を返す)  
この問題は、それぞれの小文字に対応した26個のBITを持って、区間[l,r]の正の和の個数を調べればいい。([AC code](https://codeforces.com/contest/1234/submission/73413137))  

・[AtCoder ARC033-C データ構造](https://atcoder.jp/contests/arc033/tasks/arc033_3)  
lower_boundを使えばいい。([AC code](https://atcoder.jp/contests/arc033/submissions/10947418))  

・[yukicoder No.742 にゃんにゃんにゃん 猫の挨拶](https://yukicoder.me/problems/no/742)  
転倒数を出力する。([AC code](https://yukicoder.me/submissions/445086))

# To do
・区間更新  
・2D化BIT  

https://codeforces.com/contest/986/problem/B (転倒数)   
https://codeforces.com/contest/1268/problem/C (2D)  
https://codeforces.com/contest/459/problem/D (転倒数)  
https://codeforces.com/contest/846/problem/D (2D)  
https://codeforces.com/contest/341/problem/D (2D)  
