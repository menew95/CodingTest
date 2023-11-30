#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems)
{
    int _alp_max = -1, _cop_max = -1;
    
    for(auto& problem : problems)
    {
        _alp_max = max(_alp_max, problem[0]);
        _cop_max = max(_cop_max, problem[1]);
    }
    
    alp = min(alp, _alp_max); 
    cop = min(cop, _cop_max); 
    
    int _dp[155][155];
    
    for(int i = 0; i <= _alp_max; i++) 
        fill(_dp[i], _dp[i] + _cop_max + 1, INT_MAX);
    
    _dp[alp][cop] = 0; // dp의 초기값
    
    for(int i = alp; i <= _alp_max; i++)
    {
        for(int j = cop; j <= _cop_max; j++)
        {
            // 공부했을때와 기존의 경우 중 최솟값
            _dp[i + 1][j] = min(_dp[i + 1][j], _dp[i][j] + 1);
            _dp[i][j + 1] = min(_dp[i][j + 1], _dp[i][j] + 1);
            
            // 문제를 풀어서 능력치를 올리는 경우 dp 갱신
            for(auto& problem : problems)
            {
                int _alp_req, _cop_req, _alp_rwd, _cop_rwd, _cost;
                
                _alp_req = problem[0];
                _cop_req = problem[1];
                _alp_rwd = problem[2];
                _cop_rwd = problem[3];
                _cost = problem[4];
                
                if(i < _alp_req || j < _cop_req) continue;
                
                int _alp_nxt = min(_alp_max, i + _alp_rwd);
                int _cop_nxt = min(_cop_max, j + _cop_rwd);
                
                _dp[_alp_nxt][_cop_nxt] = min(_dp[_alp_nxt][_cop_nxt], _cost + _dp[i][j]);
            }
        }
    }
    
    return _dp[_alp_max][_cop_max];
}