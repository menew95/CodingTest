#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n)
{
	vector<int> _dp(n);

	_dp[0] = 1;
	_dp[1] = 2;

	for (int i = 2; i < n; i++)
	{
		_dp[i] = (_dp[i - 1] + _dp[i - 2]) % 10007;
	}

	return _dp.back();

}

int main()
{
	int _n;

	cin >> _n;

	cout << solution(_n) << endl;
}