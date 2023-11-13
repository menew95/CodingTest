#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    int _map[101][101];
    
    for(int i = 0; i < rectangle.size(); i++)
    {
        int _minX = rectangle[i][0] * 2;
        int _minY = rectangle[i][1] * 2;
        int _maxX = rectangle[i][2] * 2;
        int _maxY = rectangle[i][3] * 2;
        for(int dx = _minX; dx <= _maxX; dx++)
        {
            _map[dx][_minY] = 1;
            _map[dx][_maxY] = 1;
        }
        
        for(int dy = _minY; dy <= _maxY; dy++)
        {
            _map[_minX][dy] = 1;
            _map[_maxX][dy] = 1;
        }
    }
    
    for(int i = 0; i < rectangle.size(); i++)
    {
        int _minX = rectangle[i][0] * 2;
        int _minY = rectangle[i][1] * 2;
        int _maxX = rectangle[i][2] * 2;
        int _maxY = rectangle[i][3] * 2;
        
        for(int dx = _minX + 1; dx < _maxX; dx++)
        {
            for(int dy = _minY + 1; dy < _maxY; dy++)
            {
                _map[dx][dy] = 0;
            }
        }
    }
    
    struct Node
    {
        int _x, _y, _cnt;  
    };
    
    queue<Node> _queue;
    int _dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
    
    _queue.push({characterX * 2, characterY * 2, 0});
    
    while(!_queue.empty())
    {
        auto _cur = _queue.front();
        _queue.pop();
        
        if(_cur._x == itemX * 2 && _cur._y == itemY * 2)
        {
            answer = _cur._cnt;
            break;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int _nx = _dir[i][0] + _cur._x;
            int _ny = _dir[i][1] + _cur._y;
            
            if(_nx < 0 || _nx > 100 || _ny < 0 || _ny > 100)
                continue;
            
            if(_map[_nx][_ny] == 0)
                continue;
            
            _map[_nx][_ny] = 0;
            _queue.push({_nx, _ny, _cur._cnt + 1});
        }
    }
    
    return answer / 2;
}