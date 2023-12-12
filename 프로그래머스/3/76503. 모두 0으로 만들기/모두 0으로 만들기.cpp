#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

long long dfs(int cur, int parent, vector<vector<int>>& tree, vector<long long>& node)
{
    long long _ret = 0;
    
    for(int i = 0; i < tree[cur].size(); i++)
        if(tree[cur][i] != parent) 
            _ret += dfs(tree[cur][i], cur, tree, node);
    
    node[parent] += node[cur];
    
    return _ret + abs(node[cur]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    if(accumulate(a.begin(), a.end(), 0) != 0)
       return -1;
    
    vector<long long> _node(a.begin(), a.end());
    vector<vector<int>> _tree(a.size());
    
    for(int i = 0; i < edges.size(); i++)
    {
        _tree[edges[i][0]].push_back(edges[i][1]);
        _tree[edges[i][1]].push_back(edges[i][0]);
    }
    
    return dfs(0, 0, _tree, _node);
}