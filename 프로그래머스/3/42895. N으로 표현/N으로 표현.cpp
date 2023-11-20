#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int make_number(const int& N, const int& count) {
	int ret = 0;
	for (int i = 0; i < count; ++i)
		ret += N * pow(10, i);
	return ret;
}

int solution(int N, int number) {
    int answer = 0;
    
    vector<int> dp[9];
	// 1자릿수
	dp[1].push_back(make_number(N, 1));
    
    for (int i = 0; i < dp[1].size(); ++i)
		if (number == dp[1][i])
			return 1;
    
    // 2자릿수 ~ 8자릿수
	for (int x = 2; x <= 8; ++x) {
		dp[x].push_back(make_number(N, x));
		for (int i = 1; i < x; ++i)
			for (auto& j : dp[i]) {
				if (j == 0)			continue;	// 0인 경우, 계산에 의미가 없음 (나눗셈 연산 문제 포함)
				for (auto& k : dp[x - i])
				{
					if (k == 0)		continue;	// 0인 경우, 계산에 의미가 없음 (나눗셈 연산 문제 포함)
					dp[x].push_back(j * k), dp[x].push_back(j / k), dp[x].push_back(j + k), dp[x].push_back(j - k);
				}
			}
		for (int i = 0; i < dp[x].size(); ++i)
			if (number == dp[x][i])
				return x;
	}
	// 9자릿수 이상
	return -1;
    
    return answer;
}