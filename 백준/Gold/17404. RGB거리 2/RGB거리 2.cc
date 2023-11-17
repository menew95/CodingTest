#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>>& paint)
{
	int _ret = 1000000;
	vector<vector<vector<int>>> _dp(3, vector<vector<int>>(paint.size(), vector<int>(3)));

	_dp[0][0] = paint[0];
	_dp[1][0] = paint[0];
	_dp[2][0] = paint[0];

	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			if(i == k)
				_dp[k][0][i] = paint[0][i];
			else
				_dp[k][0][i] = 1000000;
		}

		for (int i = 1; i < paint.size(); i++)
		{
			_dp[k][i][0] = paint[i][0] + min(_dp[k][i - 1][1], _dp[k][i - 1][2]);
			_dp[k][i][1] = paint[i][1] + min(_dp[k][i - 1][0], _dp[k][i - 1][2]);
			_dp[k][i][2] = paint[i][2] + min(_dp[k][i - 1][0], _dp[k][i - 1][1]);
		}

		for (int i = 0; i < 3; i++)
		{
			if(i == k)
				continue;

			_ret = min(_ret, _dp[k].back()[i]);
		}
	}

	return _ret;
}

int main()
{
	int _cnt;

	cin >> _cnt;

	vector<vector<int>> _paint(_cnt, vector<int>(3));

	for (int i = 0; i < _cnt; i++)
	{
		cin >> _paint[i][0] >> _paint[i][1] >> _paint[i][2];
	}

	cout << solution(_paint) << endl;
}