
/*
bit列を持つtrie木 multisetのように扱える
ビット長Bに対して
O(B)の操作
insert(x) : 値 x を集合に（一つ）追加 
erase(x) : 値 x を集合から（一つ）削除 
max_element/min_elemet() : 集合内の最大/最小値を取得
lower_bound(x): 集合内で値 x 以上の最小の要素の番号を取得. ここでの番号とは小さい方から何番目かということ. 
upper_bound(x) : より大きい 最小の要素の番号を取得. ここでの番号とは小さい方から何番目かということ.
kth_element(k) : k 番目に小さい要素を取得
max_element/min_element(x) : 集合内の値の中で, 値 x と XOR したときに最大/最小になる値の取得
kth_element(k, x) : 集合内の値の中で, 値 x で XOR したときの k 番目に小さい値の取得(未実装)

O(1)の操作(遅延評価による)
xor_all(x) : 全要素を値 x で XOR した値に変更

参考
http://kazuma8128.hatenablog.com/entry/2018/05/06/022654
*/

template <typename U = unsigned, int B = 32>
class lazy_binary_trie
{
    struct node
    {
        int cnt;
        U lazy;
        node *child[2];
        node() : cnt(0), lazy(0), child{nullptr, nullptr} {}
    };

    void push(node *t, int b)
    {
        if ((t->lazy >> (U)b) & (U)1)
            swap(t->child[0], t->child[1]);
        if (t->child[0])
            t->child[0]->lazy ^= t->lazy;
        if (t->child[1])
            t->child[1]->lazy ^= t->lazy;
        t->lazy = 0;
    }

    node *add(node *t, U val, int b = B - 1)
    {
        if (!t)
            t = new node;
        t->cnt += 1;
        if (b < 0)
            return t;
        push(t, b);
        bool f = (val >> (U)b) & (U)1;
        t->child[f] = add(t->child[f], val, b - 1);
        return t;
    }

    node *sub(node *t, U val, int b = B - 1)
    {
        assert(t);
        t->cnt -= 1;
        if (t->cnt == 0)
            return nullptr;
        if (b < 0)
            return t;
        push(t, b);
        bool f = (val >> (U)b) & (U)1;
        t->child[f] = sub(t->child[f], val, b - 1);
        return t;
    }

    U get_min(*node, U val, int b = B - 1)
    {
        assert(t);
        if (b < 0)
            return 0;
        push(t, b);
        bool f = (val >> (U)b) & (U)1;
        f ^= !t->child[f];
        return get_min(t->child[f], val, b - 1) | ((U)f << (U)b);
    }

    U get(node *t, int k, int b = B - 1)
    {
        if (b < 0)
            return 0;
        push(t, b);
        int m = t->child[0] ? t->child[0]->cnt : 0;
        return k < m ? get(t->child[0], k, b - 1) : get(t->child[1], k - m, b - 1) | ((U)1 << (U)b);
    }

    int count_lower(node *t, U val, int b = B - 1)
    {
        if (!t || b < 0)
            return 0;
        push(t, b);
        bool f = (val >> (U)b) & (U)1;
        return (f && t->child[0] ? t->child[0]->cnt : 0) + count_lower(t->child[f], val, b - 1);
    }
    node *root;

public:
    lazy_binary_trie() : root(nullptr);

    int size() const { return root ? root->cnt : 0; }
    bool empty() const { return !root; }
    void insert(U val) { root = add(root, val); }
    void erase(U val) { root = sub(root, val); }

    U max_element(U bias = 0) { return get_min(root, ~bias); }
    U min_element(U bias = 0) { return get_min(root, bias); }
    int lower_bound(U val) { return count_lower(root, val); }     // return id
    int upper_bound(U val) { return count_lower(root, val + 1); } // return id

    U operator[](int k)
    {
        assert(0 <= k && k < size());
        return get(root, k);
    }

    U kth_min(int k)
    {
        assert(0 <= k && k < size());
        node *t = root;
        while (true)
        {
            int c = t->child[0] ? t->child[0]->sum : 0;
            if (c <= k && k < c + t->cnt)
                return t->pos;
            if (k < c)
                t = t->child[0];
            else
                k -= c + t->cnt, t = t->child[1];
        }
    }

    int count(U val)
    {
        if (!root)
            return 0;
        node *t = root;
        for (int i = B - 1; i >= 0; i--)
        {
            push(t, i);
            t = t->child[(val >> (U)i) & (U)1];
            if (!t)
                return 0;
        }
        return t->cnt;
    }
};

int main()
{
    lazy_binary_trie<> trie;
}
