#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    vector<int> answer(sources.size());
    
    vector<vector<int>> _graphs(n + 1);
    
    for(int i = 0; i < roads.size(); i++)
    {
        _graphs[roads[i][0]].push_back(roads[i][1]);
        _graphs[roads[i][1]].push_back(roads[i][0]);
    }
    
    vector<bool> _visit(n + 1, false);
    vector<int> _result(n + 1, -1);
    queue<pair<int, int>> _queue;
    
    _queue.push({destination, 0});
    _result[destination] = 0;
    _visit[destination] = true;
    
    while(!_queue.empty())
    {
        auto _cur = _queue.front();
        _queue.pop();
        
        for(int i = 0; i < _graphs[_cur.first].size(); i++)
        {
            if(_visit[_graphs[_cur.first][i]])
                continue;
            
            _visit[_graphs[_cur.first][i]] = true;
            _result[_graphs[_cur.first][i]] = _cur.second + 1;
            _queue.push({_graphs[_cur.first][i], _cur.second + 1});
        }
    }
    
    for(int i = 0; i < sources.size(); i++)
    {
        answer[i] = _result[sources[i]];
    }
    
    return answer;
}