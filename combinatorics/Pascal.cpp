#include <iostream>
#include <vector>
using namespace std;

using ll = int_fast64_t;
vector<vector<ll>> Pascal(int N)
{
	vector<vector<ll>> pascal(N + 1, vector<ll>(N + 1));
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				pascal[i][j] = 1;
			else
				pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
		}
	}
	return pascal;
}

int main()
{
	vector<vector<ll>> pas = Pascal(15);
	cout << pas[10][4] << "\n";
}
