#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<pair<int, int>>> can_rot(vector<vector<int>>& board, pair<int, int> r, pair<int, int> l)
{
    vector<vector<pair<int, int>>> _ret;
    
    
    
    return _ret;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    struct Node
    {
        pair<int, int> _r, _l;
        int _t = 0;
        int _rot = 0;
    };
    
    int _n = board.size();
    int _dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    queue<Node> _queue;
    _queue.push({{0, 0}, {0, 1}, 0, 0});
    
    vector<vector<vector<bool>>> _visit(500, vector<vector<bool>>(500, vector<bool>(2, false)));
    _visit[0][0][0] = true;
    
    
    while(!_queue.empty())
    {
        auto [_r, _l, _t, _rot] = _queue.front();
        _queue.pop();
        
        //cout << _r.first << ',' << _r.second << '/' << _l.first << ',' << _l.second << endl;
        
        if((_r.first == _n - 1 && _r.second == _n - 1) ||
          (_l.first == _n - 1 && _l.second == _n - 1))
        {
            answer = _t;
            break;
        }
        
        for(int i = 0; i < 4; i++)
        {
            pair<int, int> _nr = {_r.first + _dir[i][0], _r.second + _dir[i][1]};
            pair<int, int> _nl = {_l.first + _dir[i][0], _l.second + _dir[i][1]};
            
            if(_nr.first < 0 || _nr.second < 0 || _nr.first == _n || _nr.second == _n
              || _nl.first < 0 || _nl.second < 0 || _nl.first == _n || _nl.second == _n
              || board[_nr.first][_nr.second] || board[_nl.first][_nl.second]
              || _visit[_nr.first][_nr.second][_rot])
                continue;
            
            _visit[_nr.first][_nr.second][_rot] = true;
            
            _queue.push({_nr, _nl, _t + 1, _rot});
        }
        
        if(!_rot)
        {
            pair<int, int> _nr , _nl;
            // 가로
            if(_r.first > 0 && !board[_r.first - 1][_r.second] && !board[_l.first - 1][_l.second])
            {
                // 00
                // 11
                if(!_visit[_r.first - 1][_r.second][1])
                {
                    // 10
                    // 10
                    _nr = {_r.first - 1, _r.second};
                    _nl = {_r.first, _r.second};
                    
                    _visit[_r.first - 1][_r.second][1] = true;
                    _queue.push({_nr, _nl, _t + 1, 1});
                }
                
                if(!_visit[_r.first - 1][_l.second][1])
                {
                    // 01
                    // 01
                    _nr = {_l.first - 1, _l.second};
                    _nl = {_l.first, _l.second};
                 
                    _visit[_r.first - 1][_l.second][1] = true;
                    _queue.push({_nr, _nl, _t + 1, 1});
                }
            }
            
            if(_r.first < _n - 1 && !board[_r.first + 1][_r.second] && !board[_l.first + 1][_l.second])
            {
                // 11
                // 00
                if(!_visit[_r.first][_r.second][1])
                {
                    // 10
                    // 10
                    _nr = {_r.first, _r.second};
                    _nl = {_r.first + 1, _r.second};
                    
                    _visit[_r.first][_r.second][1] = true;
                    _queue.push({_nr, _nl, _t + 1, 1});
                }
                
                if(!_visit[_l.first][_l.second][1])
                {
                    // 01
                    // 01
                    _nr = {_l.first, _l.second};
                    _nl = {_l.first + 1, _l.second};
                    
                    _visit[_l.first][_l.second][1] = true;
                    _queue.push({_nr, _nl, _t + 1, 1});
                }
            }
        }
        else
        {
            pair<int, int> _nr , _nl;
            // 세로
            if(_r.second > 0 && !board[_r.first][_r.second - 1] && !board[_l.first][_l.second - 1])
            {
                // 01
                // 01
                if(!_visit[_r.first][_r.second - 1][0])
                {
                    // 11
                    // 00
                    _nr = {_r.first, _r.second - 1};
                    _nl = {_r.first, _r.second};
                    
                    _visit[_r.first][_r.second - 1][0] = true;
                    _queue.push({_nr, _nl, _t + 1, 0});
                }
                
                if(!_visit[_l.first][_l.second - 1][0])
                {
                    // 00
                    // 11
                    _nr = {_l.first, _l.second - 1};
                    _nl = {_l.first, _l.second};
                 
                    _visit[_l.first][_l.second - 1][0] = true;
                    _queue.push({_nr, _nl, _t + 1, 0});
                }
            }
            
            if(_r.second < _n - 1 && !board[_r.first][_r.second + 1] && !board[_l.first][_l.second + 1])
            {
                // 10
                // 10
                if(!_visit[_r.first][_r.second][0])
                {
                    // 11
                    // 00
                    _nr = {_r.first, _r.second};
                    _nl = {_r.first, _r.second + 1};
                    
                    _visit[_r.first][_r.second][0] = true;
                    _queue.push({_nr, _nl, _t + 1, 0});
                }
                
                if(!_visit[_l.first][_l.second][0])
                {
                    // 00
                    // 11
                    _nr = {_l.first, _l.second};
                    _nl = {_l.first, _l.second + 1};
                 
                    _visit[_l.first][_l.second][0] = true;
                    _queue.push({_nr, _nl, _t + 1, 0});
                }
            }
        }
    }
    
    return answer;
}