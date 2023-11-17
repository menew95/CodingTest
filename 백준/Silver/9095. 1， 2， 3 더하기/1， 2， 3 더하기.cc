#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
	vector<int> _dp(n + 1, 0);

	_dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3 && i - j >= 0; j++)
		{
			_dp[i] += _dp[i - j];
		}
	}

	return _dp[n];
}

int main()
{
	int _cnt;

	cin >> _cnt;

	vector<int> _n(_cnt);

	for (int i = 0; i < _cnt; i++)
	{
		cin >> _n[i];
	}

	for (int i = 0; i < _cnt; i++)
	{
		cout << solution(_n[i]) << endl;
	}

	return 0;
}