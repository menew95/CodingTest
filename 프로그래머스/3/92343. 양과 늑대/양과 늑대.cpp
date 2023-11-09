#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

int g_answer = 1;

void dfs(int bit, int idx, int wolf, int sheep, vector<int> next, vector<bool>& visit, vector<vector<int>>& graphs, vector<int>& info)
{
    if(info[idx])
        wolf++;
    else
        sheep++;
    
    if(wolf >= sheep) return;
    
    g_answer = max(g_answer, sheep);
    
    for(int i = 0; i < next.size(); i++)
    {
        int _tmp = bit | (1 << next[i]);
        
        if(visit[_tmp])
        {
            continue;
        }
        
        auto _copy = next;
        _copy.erase(_copy.begin() + i);
        
        for(int j= 0; j < graphs[next[i]].size(); j++)
            _copy.push_back(graphs[next[i]][j]);
        
        visit[_tmp] = true;
        
        dfs(_tmp, next[i], wolf, sheep, _copy, visit, graphs, info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    vector<vector<int>> _graphs(info.size());
    
    vector<bool> _visit(pow(2, info.size()), false);
    
    for(int i = 0; i < edges.size(); i++)
    {
        _graphs[edges[i][0]].push_back(edges[i][1]);
    }
    
    vector<int> _next;
    for(int i = 0; i < _graphs[0].size(); i++)
    {
        _next.push_back(_graphs[0][i]);
    }
    
    dfs(1, 0, 0, 0, _next, _visit, _graphs, info);
    
    return g_answer;
}