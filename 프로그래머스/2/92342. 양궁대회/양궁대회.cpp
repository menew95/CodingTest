#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int g_diff = 0;
vector<int> g_score;

void dfs(int depth, int idx, vector<int>& info, vector<int>& score)
{
    if(depth == 0)
    {
        int _diff = 0;
        int _r = 0, _a = 0;
        for(int i = 0; i <= 10; i++)
        {
            if(info[i] == 0 && score[i] == 0)
                continue;
            
            if(info[i] < score[i])
                _r += 10 - i;
            else if(info[i] >= score[i])
                _a += 10 - i;
        }
        
        if(g_diff < _r - _a)
        {
            _diff = _r - _a;
            g_diff = _diff;
            g_score = score;
        }
    }
    else
    {
        for(int i = idx; i >= 0; i--)
        {
            score[i]++;
            dfs(depth - 1, i, info, score);
            score[i]--;
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    vector<int> _score(11, 0);
    
    dfs(n, 10, info, _score);
    
    if(g_diff == 0)
        answer.push_back(-1);
    else
        answer = g_score;
    
    return answer;
}