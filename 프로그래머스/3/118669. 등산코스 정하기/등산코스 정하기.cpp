#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

struct Node
{
    int _n, _intensity;
};

struct cmp
{
    bool operator()(Node a, Node b)
    {
        return a._intensity < b._intensity;
    }
};

vector<vector<pair<int, int>>> g_paths;
vector<bool> g_gates;
vector<bool> g_summits;
vector<int> g_intens;
vector<int> g_answer;

void dij(Node node, int n)
{
    vector<bool> _visit(n + 1, false);
    priority_queue<Node, vector<Node>, cmp> _pq;
    
    _pq.push(node);
    
    _visit[node._n] = true;
    
    while(!_pq.empty())
    {
        auto [_idx, _inten] = _pq.top();
        _pq.pop();
        
        if(_inten > g_answer[1])
            continue;
        
        if(g_summits[_idx])
        {
            if(_inten < g_answer[1])
            {
                g_answer[1] = _inten;
                g_answer[0] = _idx;
            }
            else if(_inten == g_answer[1] && _idx < g_answer[0])
                g_answer[0] = _idx;
            
            continue;
        }
        
        for(auto _p : g_paths[_idx])
        {
            if(g_gates[_p.first])
                continue;
            
            int _intenTmp = max(_inten, _p.second);
            
            if(g_intens[_p.first] <= _intenTmp)
                continue;
            
            g_intens[_p.first] = _intenTmp;
            
            _pq.push({_p.first, _intenTmp});
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    g_answer = vector<int>(2, INT_MAX);
    
    g_paths = vector<vector<pair<int, int>>>(n + 1);
    
    g_intens = vector<int>(n + 1, INT_MAX);
    
    for(int i = 0; i < paths.size(); i++)
    {
        g_paths[paths[i][0]].push_back({paths[i][1], paths[i][2]});
        g_paths[paths[i][1]].push_back({paths[i][0], paths[i][2]});
    }
    
    g_summits = vector<bool>(n + 1, false);
    g_gates = vector<bool>(n + 1, false);
    
    for(auto i : summits)
        g_summits[i] = true;
    for(auto i : gates)
        g_gates[i] = true;
    
    for(auto _gate : gates)
    {
        dij({_gate, 0}, n);
    }
    
    return g_answer;
}