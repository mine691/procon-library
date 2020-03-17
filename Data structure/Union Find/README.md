# 概要
Union Find ( Disjoint Set Union とも言われている, 以下 UF )は、互いに素な集合のマージを高速に行うデータ構造である。  

# 関数
| 名前 | 説明 | 計算量 |
|:----------:|:-----------:|:------------:|
| unite(int x, int y) | x, y の含まれる集合をマージする | O(α(N)) |
| root(int k) | k の親を取得する | - |
| size(int x) | x が含まれる集合の要素数を返す | O(1) |
| same(int x, int y) | x, y が同じ集合に含まれているかの真偽値 | O(1) |
| connected_component() | グラフ全体の連結成分の個数を返す | O(1) |
| get_set(int x) | x の属している集合の要素を列挙する (sortはされていない) | O(( x と同じ集合に属している要素数)) |

# 例
https://codeforces.com/contest/1253/problem/D  
https://codeforces.com/contest/500/problem/B  
https://codeforces.com/contest/25/problem/D  
https://atcoder.jp/contests/abc157/tasks/abc157_d  
https://codeforces.com/contest/1012/problem/B  
https://codeforces.com/contest/1209/problem/D  
https://atcoder.jp/contests/abc120/tasks/abc120_d  
https://atcoder.jp/contests/abc126/tasks/abc126_e

# To do
Verify  
典型テクを書く 
undo可能UF(Dynamic connectivity	)  
weighted-UF  
半永続化/永続化  
二部グラフ判定  
実装についての説明
