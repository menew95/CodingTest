#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>>& paint)
{
	vector<vector<int>> _dp(paint.size(), vector<int>(3));

	/*
		3
		26 40 83
		49 60 57
		13 89 99
	*/

	_dp[0] = paint[0];

	for (int i = 1; i < paint.size(); i++)
	{
		_dp[i][0] = paint[i][0] + min(_dp[i - 1][1], _dp[i - 1][2]);
		_dp[i][1] = paint[i][1] + min(_dp[i - 1][0], _dp[i - 1][2]);
		_dp[i][2] = paint[i][2] + min(_dp[i - 1][0], _dp[i - 1][1]);
	}

	return min(_dp.back()[0], min(_dp.back()[1], _dp.back()[2]));;
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