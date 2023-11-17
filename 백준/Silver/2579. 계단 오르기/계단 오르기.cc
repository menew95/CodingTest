#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& score)
{
	vector<int> _dp(score.size(), 0);

	_dp[0] = score[0];

	_dp[1] = max(score[1], score[0] + score[1]);

    if(score.size() == 2)
        return _dp[1];
    
	_dp[2] = score[2] + max(score[0], score[1]);
    
    if(score.size() == 3)
	    return max(_dp[2], score[0] + score[1]);

	for (int i = 3; i < score.size(); i++)
	{
		_dp[i] = max(_dp[i - 2] + score[i], score[i - 1] + score[i] + _dp[i - 3]);
	}

	return _dp.back();
}

int main()
{
	int _cnt;

	cin >> _cnt;

	vector<int> _score(_cnt);

	for (int i = 0; i < _cnt; i++)
	{
		cin >> _score[i];
	}

	cout << solution(_score) << endl;
}