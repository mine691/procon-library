#include <iostream>
#include <vector>
using namespace std;

vector<int> eratosthenes(int N)
{
	if (N < 2)
		return vector<int>();

	vector<int> res;
	vector<bool> prime(N + 1, 1);
	prime[0] = prime[1] = false;

	for (int i = 2; i * i <= N; ++i)
	{
		if (prime[i])
		{
			for (int j = 2 * i; j <= N; j += i)
			{
				prime[j] = false;
			}
		}
	}

	res.emplace_back(2);

	for (int i = 3; i <= N; i += 2)
	{
		if (prime[i] == true)
			res.emplace_back(i);
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	auto prime = eratosthenes(N);
}
