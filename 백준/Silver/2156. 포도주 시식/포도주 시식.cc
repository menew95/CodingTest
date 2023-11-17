#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& wine)
{
	vector<int> _dp(wine.size());

	_dp[0] = wine[0];
	_dp[1] = wine[0] + wine[1];
	_dp[2] = max(max(wine[0] + wine[2], wine[1] + wine[2]), _dp[1]);

	for (int i = 3; i < wine.size(); i++)
	{
		_dp[i] = max(_dp[i - 1], wine[i] + max(_dp[i - 2], wine[i - 1] + _dp[i - 3]));
	}

	return _dp.back();
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int _cnt;

	cin >> _cnt;

	vector<int> _wine(_cnt);

	for (int i = 0; i < _cnt; i++)
	{
		cin >> _wine[i];
	}

	cout << solution(_wine) << endl;
}