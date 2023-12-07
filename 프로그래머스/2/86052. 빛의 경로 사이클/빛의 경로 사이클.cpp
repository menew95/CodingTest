#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;

int g_dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상하좌우
map<char, vector<int>> g_rot;

int bfs(tuple<int, int, int> pos, vector<string>& grid, vector<vector<vector<bool>>>& visit)
{
    int _ret = 1;
    
    queue<tuple<int, int, int>> _queue;
    _queue.push(pos);
    
    while(!_queue.empty())
    {
        auto [_x, _y, _d] = _queue.front();
        _queue.pop();
            
        int _nx = _x + g_dir[_d][0];
        int _ny = _y + g_dir[_d][1];
        
        if(_nx < 0) _nx = grid.size() - 1;
        else if(_nx == grid.size()) _nx = 0;
        
        if(_ny < 0) _ny = grid[0].length() - 1;
        else if(_ny == grid[0].length()) _ny = 0;
        
        int _nd = g_rot[grid[_nx][_ny]][_d];
        
        if(visit[_nx][_ny][_nd])
            break;
        
        visit[_nx][_ny][_nd] = true;
        
        _ret++;
        
        _queue.push({_nx, _ny, _nd});
    }
    
    return _ret;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    g_rot['S'] = {0, 1, 2, 3}; // 상하좌우
    g_rot['R'] = {2, 3, 1, 0}; // 좌우하상
    g_rot['L'] = {3, 2, 0, 1}; // 우좌상하
    
    vector<vector<vector<bool>>> _visit(grid.size(), vector<vector<bool>>(grid[0].length(), vector<bool>(4, false)));
    
    for(int i = 0; i < _visit.size(); i++)
    {
        for(int j = 0; j < _visit[0].size(); j++)
        {
            for(int k = 0; k < 4; k++)
            {
                if(_visit[i][j][k])
                    continue;
                
                _visit[i][j][k] = true;
                
                answer.push_back(bfs({i, j, k}, grid, _visit));
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}