#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    
    sort(money.begin(), money.end());
    
    vector<int> _dp(n + 1, 0);
    _dp[0] = 1;
    
    //1 1
    //2 11 2
    //3 111 21
    //4 1111 211 22
    //6 111111 21111 2211 222 51
    //7 1111111 211111 22111 2221 511 52
    //8 11111111 2111111 221111 22211 2222 5111 521
    for(int i = 0; i < money.size(); i++)
    {
        for(int j = money[i]; j <= n; j++)
            _dp[j] += _dp[j - money[i]];
    }
    
    return _dp[n];
}