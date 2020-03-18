#include <iostream>
using namespace std;

/*
真上から見て
l : 左, r : 右
f : 前, b : 後ろ
d : 下, u : 上
*/

struct Dice
{
    int l, r, f, b, d, u;
    //前に回転
    void RollN()
    {
        int buff = d;
        d = f, f = u, u = b, b = buff;
    }
    //後ろに回転
    void RollS()
    {
        int buff = d;
        d = b, b = u, u = f, f = buff;
    }
    //左に回転
    void RollW()
    {
        int buff = d;
        d = l, l = u, u = r, r = buff;
    }
    //右に回転
    void RollE()
    {
        int buff = d;
        d = r, r = u, u = l, l = buff;
    }
    //時計回りに回転
    void RollR()
    {
        int buff = f;
        f = r, r = b, b = l, l = buff;
    }
    //反時計回りに回転
    void RollL()
    {
        int buff = f;
        f = l, l = b, b = r, r = buff;
    }
};

/*
0 -> 上, 1-> 後ろ
2 -> 右, 3-> 左
4 -> 前, 5-> 下
   4
3  0  2  5
   1
*/

Dice make_dice(int a[])
{
    Dice dice;
    dice.u = a[0], dice.b = a[1], dice.r = a[2], dice.l = a[3], dice.f = a[4], dice.d = a[5];
    return dice;
}

//p : 上面,　q : 後面, 同じ面があれば、どれかに合わせる
void set_dice(Dice &dice, int p, int q)
{
    for (int i = 0; i < 7; i++)
    {
        if (i < 4)
            dice.RollE();
        else
            dice.RollN();
        if (p == dice.u)
            break;
    }
    for (int i = 0; i < 4; i++)
    {
        dice.RollR();
        if (q == dice.b)
            break;
    }
}

//2つのサイコロが同じか
bool dice_equal(Dice dice1, Dice dice2)
{
    bool eq = false;
    for (int i = 0; i < 50; i++)
    {
        set_dice(dice2, dice1.u, dice1.b);
        if (dice1.u == dice2.u && dice1.d == dice2.d && dice1.r == dice2.r && dice1.l == dice2.l && dice1.f == dice2.f && dice1.b == dice2.b)
            eq = true;
    }
    return eq;
}

int main()
{
    return 0;
}
