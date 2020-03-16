# 概要
Binary Indexed Tree(以下BIT)は、数列に対して以下の二種類にクエリを高速に扱うデータ構造である。  
・一点加算  
・区間和  
BITの特徴として、実装が楽で省メモリなことが挙げられる。また、本実装は1-indexedであることに注意する。

# 関数
BITの長さをNとする。  
| 名前 | 説明 | 計算量 |
|:----------:|:-----------:|:------------:|
| sum(int k) | 閉区間[1,K]の和を返す | O(log N) |
| add(int k, T w) | 第k項にwを加える　| O(log N) |
| getSum(int x, int y) | 半開区間[x,y)の和を返す | O(log N) |
| inversion(vector<int> p) | 順列pの転倒数を返す | O(log N) |
