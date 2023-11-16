#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int g_answer = 2000000000;

int calc_fatigue(int idx, int picks, vector<string>& minerals)
{
    int _ret = 0;
    
    map<char, vector<int>> _m = 
    {
        {'d', { 1, 5, 25 }}, {'i', { 1, 1, 5 }}, {'s',{ 1, 1, 1 }}
    };
    
    for(int i = 0; i < 5 && i + idx < minerals.size(); i++)
    {
        _ret += _m[minerals[i + idx][0]][picks];
    }
    
    return _ret;
}

void dfs(vector<int>& picks, vector<string>& minerals, int depth, int m)
{
    if(depth > minerals.size() || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0))
    {
        g_answer = g_answer < m ? g_answer : m;
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            if(picks[i] == 0)
                continue;
            
            picks[i] -= 1;
            
            int _fatigue = calc_fatigue(depth, i, minerals);
            
            dfs(picks, minerals, depth + 5, m + _fatigue);
            
            picks[i] += 1;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    
    dfs(picks, minerals, 0, 0);
    
    return g_answer;
}