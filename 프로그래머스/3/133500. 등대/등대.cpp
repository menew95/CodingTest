#include <string>
#include <vector>

using namespace std;

int g_answer = 0;

void dfs(int cur, int parent, vector<vector<int>>& graphs, vector<bool>& lights)
{
    for(int i = 0; i < graphs[cur].size(); i++)
    {
        if (graphs[cur][i] != parent)
        {
            dfs(graphs[cur][i], cur, graphs, lights);
            
            if (!lights[graphs[cur][i]] && !lights[cur])
            {
                lights[cur] = true;
                g_answer++;
            }
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    
    vector<vector<int>> _graphs(n + 1);
    
    for(int i = 0; i < lighthouse.size(); i++)
    {
        _graphs[lighthouse[i][0]].push_back(lighthouse[i][1]);
        _graphs[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }
    
    vector<bool> _light(n + 1, false);
    
    dfs(1, 1, _graphs, _light);
    
    return g_answer;
}