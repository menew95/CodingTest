#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    
    vector<int> _d(matrix_sizes.size() + 1);
    vector<vector<int>> _dp(matrix_sizes.size() + 1, vector<int>(matrix_sizes.size() + 1, 0));
    
    _d[0] = matrix_sizes[0][0];
    
    for (int i = 0; i < matrix_sizes.size(); i++)
    {
        _d[i + 1] = matrix_sizes[i][1];
    }
    
    for (int n = 0; n < matrix_sizes.size(); n++)
    {
        for (int i = 1; i <= matrix_sizes.size() - n; i++)
        {
            int j = i + n;
            
            if (i == j) 
                _dp[i][j] = 0;
            else
            {
                _dp[i][j] = 2000000000;
                for (int k = i; k <= j - 1; k++)
                {
                    _dp[i][j] = min(_dp[i][j], _dp[i][k] + _dp[k + 1][j] + _d[i - 1] * _d[k] * _d[j]);
                }
            }
        }
    }
    
    return _dp[1][matrix_sizes.size()];
    
}