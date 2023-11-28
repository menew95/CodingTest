#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
#include <functional>

using namespace std;


int solution(vector<vector<int>> maze) {
    int answer = 0;
    
    pair<int, int> _r_s, _r_e, _b_s, _b_e;
    
    for(int i = 0; i < maze.size(); i++)
        for(int j = 0; j < maze[0].size(); j++)
        {
            if(maze[i][j] == 1) _r_s =  {i, j};
            else if(maze[i][j] == 2) _b_s =  {i, j};
            else if(maze[i][j] == 3) _r_e =  {i, j};
            else if(maze[i][j] == 4) _b_e =  {i, j};
        }
    
    // dfs 방식
    /*vector<vector<bool>> _r_visit(maze.size(), vector<bool>(maze[0].size(), false));
    vector<vector<bool>> _b_visit(maze.size(), vector<bool>(maze[0].size(), false));
    
    _r_visit[_r_s.first][_r_s.second] = true;
    _b_visit[_b_s.first][_b_s.second] = true;
    
    function<int(pair<int, int>, pair<int, int>, int)> dfs 
        = [&](pair<int, int> r, pair<int, int> b, int cnt)
    {
        if(r == _r_e && b == _b_e)
            return cnt;
        
        vector<int> _ret = { INT_MAX };
        int _dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                int _r_x = r == _r_e ? r.first : r.first + _dir[i][0];
                int _r_y = r == _r_e ? r.second : r.second + _dir[i][1];
                
                int _b_x = b == _b_e ? b.first : b.first + _dir[j][0];
                int _b_y = b == _b_e ? b.second : b.second + _dir[j][1];
                
                if(_r_x == _b_x && _r_y == _b_y)
                    continue; // 같은 곳으로 이동시
                
                if(_r_x == b.first && _r_y == b.second 
                   && r.first == _b_x && r.second == _b_y)
                    continue; // 서로 크로스
                
                if(_r_x < 0 || _r_y < 0 || _r_x == maze.size() || _r_y == maze[0].size())
                    continue; // 빨간말이 보드 밖으로
                
                if(_b_x < 0 || _b_y < 0 || _b_x == maze.size() || _b_y == maze[0].size())
                    continue; // 파란말이 보드 밖으로
                
                if((r != _r_e && _r_visit[_r_x][_r_y]) || 
                   (b != _b_e && _b_visit[_b_x][_b_y]))
                    continue; // 방문한곳 일경우
                
                if(maze[_r_x][_r_y] == 5 || maze[_b_x][_b_y] == 5)
                    continue; // 말들이 벽으로
                
                _r_visit[_r_x][_r_y] = true;
                _b_visit[_b_x][_b_y] = true;
                
                _ret.push_back(dfs({_r_x, _r_y}, {_b_x, _b_y}, cnt + 1));
                
                _r_visit[_r_x][_r_y] = false;
                _b_visit[_b_x][_b_y] = false;
            }
        }
        
        return *min_element(_ret.begin(), _ret.end());
    };
    
    
    int result = dfs(_r_s, _b_s, 0);
    
    return result == INT_MAX ? 0 : result;*/
    
    // bfs 방식
    struct turn
    {
        pair<int, int> _red, _blue;
        int _cnt = 0;
        vector<vector<bool>> _red_visit;
        vector<vector<bool>> _blue_visit;
    };
    
    queue<turn> _queue;
    
    turn _start;
    _start._red = _r_s;
    _start._blue = _b_s;
    _start._red_visit = vector<vector<bool>>(maze.size(), vector<bool>(maze[0].size(), false));
    _start._blue_visit = vector<vector<bool>>(maze.size(), vector<bool>(maze[0].size(), false));
    
    _start._red_visit[_r_s.first][_r_s.second] = true;
    _start._blue_visit[_b_s.first][_b_s.second] = true;
    
    _queue.push(_start);
    
    int _dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    while(!_queue.empty())
    {
        auto _cur = _queue.front();
        _queue.pop();
        
        if(_cur._red == _r_e && _cur._blue == _b_e)
        {
            answer = _cur._cnt;
            break;
        }
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                int _r_x = _cur._red == _r_e ? _cur._red.first : _cur._red.first + _dir[i][0];
                int _r_y = _cur._red == _r_e ? _cur._red.second : _cur._red.second + _dir[i][1];
                
                int _b_x = _cur._blue == _b_e ? _cur._blue.first : _cur._blue.first + _dir[j][0];
                int _b_y = _cur._blue == _b_e ? _cur._blue.second : _cur._blue.second + _dir[j][1];
                
                if(_r_x == _b_x && _r_y == _b_y)
                    continue; // 같은 곳으로 이동시
                
                if(_r_x == _cur._blue.first && _r_y == _cur._blue.second 
                   && _cur._red.first == _b_x && _cur._red.second == _b_y)
                    continue; // 서로 크로스
                
                if(_r_x < 0 || _r_y < 0 || _r_x == maze.size() || _r_y == maze[0].size())
                    continue; // 빨간말이 보드 밖으로
                
                if(_b_x < 0 || _b_y < 0 || _b_x == maze.size() || _b_y == maze[0].size())
                    continue; // 파란말이 보드 밖으로
                
                if((_cur._red != _r_e && _cur._red_visit[_r_x][_r_y]) || 
                   (_cur._blue != _b_e && _cur._blue_visit[_b_x][_b_y]))
                    continue; // 방문한곳 일경우
                
                if(maze[_r_x][_r_y] == 5 || maze[_b_x][_b_y] == 5)
                    continue; // 말들이 벽으로
                
                turn _next;
                _next._red = {_r_x, _r_y};
                _next._blue = {_b_x, _b_y};
                
                _next._red_visit = _cur._red_visit;
                _next._blue_visit = _cur._blue_visit;
                
                _next._red_visit[_r_x][_r_y] = true;
                _next._blue_visit[_b_x][_b_y] = true;
                
                _next._cnt = _cur._cnt + 1;
                
                _queue.push(_next);
            }
    }
    
    return answer;
}