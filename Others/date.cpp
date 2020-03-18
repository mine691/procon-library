#include <iostream>
using namespace std;

//一年の月
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string week[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

struct date
{
	int year, month, day;
};

//西暦,月,日
int Y, M, D;

void day_input()
{
	string s;
	cin >> s;
	sscanf(s.c_str(), "%d/%d/%d", &Y, &M, &D);
}

//0埋め出力
void day_print(int Y, int M, int D) { printf("%04d/%02d/%02d\n", Y, M, D); }

bool is_leap_year(int Y)
{
	//うるう年判定, trueならday[2] = 29
	return (Y % 4 == 0 && !(Y % 100 == 0 && Y % 400 != 0));
}

void tomorrow(int &y, int &m, int &d)
{
	d++;
	if (d > days[m])
	{
		d = 1, m++;
		if (m > 12)
		{
			y++, m = 1;
		}
	}
}

//日にちの前後 a < bならafter
string after(int a[], int b[])
{
	string s[3] = {"after", "before", "equal"};
	for (int i = 0; i < 3; i++)
	{
		if (a[i] < b[i])
			return s[0];
		else if (a[i] > b[i])
			return s[1];
	}
	return s[2];
}

// 0 is Suturday
// using Zeller's congruence
int Day_of_a_week(int Y, int M, int D)
{
	if (Y < 0)
		Y = 1 - Y;
	// Gregorian -> g = - 2 C + C / 4, Julian -> - C + 5
	int y = Y % 100, C = Y / 100, g = -2 * C + C / 4;

	return (D + ((26 * (M + 1)) / 10) + y + y / 4 + g + 700000) % 7;
}

int main()
{
	cout << week[Day_of_a_week(2019, 9, 17)] << endl;
	return 0;
}
