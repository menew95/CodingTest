#include <string>
#include <vector>
#include <memory.h>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    
    int _dp[101][101];
    
    int _mod = 1000000007;
    memset(_dp, 0, sizeof(_dp));
    
    _dp[1][0] = 1;
    
    for(int i = 0; i < puddles.size(); i++)
        _dp[puddles[i][0]][puddles[i][1]] = -1;
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(_dp[i][j] == -1)
                _dp[i][j] = 0;
            else
                _dp[i][j] = (_dp[i - 1][j] + _dp[i][j - 1]) % _mod;
        }
    }
    
    return _dp[m][n];
}