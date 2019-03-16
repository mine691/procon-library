//一年の月
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//西暦,月,日
int Y, M, D;

string s;
cin >> s;
sscanf(s.c_str(), "%d/%d/%d", &Y, &M, &D);

//うるう年判定
if (Y % 4 == 0 && !(Y % 100 == 0 && Y % 400 != 0)) days[2] = 29;

void tomorrow(int &y, int &m, int &d) {
    d++;
    if (d > days[m]) {
        d = 1, m++;
        if (m > 12) {
            y++ ,m = 1;
        }
    }
}

//0埋め出力
printf("%04d/%02d/%02d\n", Y, M, D);
